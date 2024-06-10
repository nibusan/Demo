#include <DxLib.h>
#include "../SceneType.h"
#include "Menu/Inventory.h"
#include "../../GameObject/2D/UI/UI/Parts/Image/UI_Image.h"
#include "../../GameObject/2D/UI/UI/Parts/Image/UI_ImageRenderer.h"
#include "../../GameObject/2D/UI/UI/Original/Inventory/UI_Inventory.h"
#include "../../GameObject/2D/UI/UI/Original/Inventory/UI_InventoryRenderer.h"
#include "../../GameObject/2D/UI/UI/UI_Info.h"
#include "Item/Item.h"
#include "../../Managers/ResourceManager.h"
#include "../../Managers/RenderManager.h"
#include "../../Managers/InputManager.h"
#include "../../Managers/SceneManager.h"
#include "../../GameObject/2D/UI/UILayer/UILayer.h"
#include "../../GameObject/2D/UI/UILayer/UILayerInfo.h"
#include "../../Library/imgui/imgui.h"
#include "../../Library/imgui/backends/imgui_impl_dx11.h"
#include "../../Library/imgui/backends/imgui_impl_win32.h"
#include "../../Library/imgui/misc/cpp/imgui_stdlib.h"
#include "../../DebugTools/DebugLog.h"
#include "InventorySystemScene.h"

InventorySystemScene::InventorySystemScene(void) {
	// ���̃V�[���̎�ނ��Z�b�g
	type_ = Scene::TYPE::INVENTORY_SYSTEM;
	DebugLog::GetInstance().AddLog({1.0f,"InventorySystemScene", 0xFF00FF});
}

void InventorySystemScene::Init(void) {
	// UILayer�̓ǂݍ��� & ������
	uiLayer_ = std::make_unique<UILayer>();
	uiLayer_->LoadUILayer(UILayerInfo::TYPE::INVENTORY_SYSTEM_MENU);
	uiLayer_->Init();

	// �R���X�g���N�^�o�R�ŃA�C�e�����m�����������r����֐��I�u�W�F�N�g��n��
	inventory_ = std::make_shared<Inventory<Item>>(&Item::Equal);
	inventory_->Init();

	// �A�C�e�����Z�b�g
	inventory_->AddItem(std::make_shared<Item>(0, 1));
	inventory_->AddItem(std::make_shared<Item>(1, 1));
	inventory_->AddItem(std::make_shared<Item>(2, 1));
	inventory_->AddItem(std::make_shared<Item>(3, 1));
	inventory_->AddItem(std::make_shared<Item>(4, 1));
	inventory_->AddItem(std::make_shared<Item>(5, 1));
	inventory_->AddItem(std::make_shared<Item>(6, 1));
	inventory_->AddItem(std::make_shared<Item>(7, 1));
	inventory_->AddItem(std::make_shared<Item>(8, 1));
	inventory_->AddItem(std::make_shared<Item>(9, 1));
	inventory_->AddItem(std::make_shared<Item>(10, 1));
	inventory_->AddItem(std::make_shared<Item>(11, 1));
	inventory_->AddItem(std::make_shared<Item>(12, 1));
	inventory_->AddItem(std::make_shared<Item>(13, 1));
	inventory_->AddItem(std::make_shared<Item>(14, 1));
	inventory_->AddItem(std::make_shared<Item>(15, 1));
	addItemID_ = 0;

	// ���\�[�X�t�@�C���擾�p
	auto& resourceManager = ResourceManager::GetInstance();

	// �C���x���g����UI�𐶐�
	std::weak_ptr<Graphic> image_Inventory = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_INVENTORY").lock());
	std::weak_ptr<Graphic> image_Item = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_ITEMS").lock());
	uiInventory_ = std::make_shared<UI_Inventory>(
		image_Inventory.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::CENTER_CENTER,
		false,
		nullptr,
		std::weak_ptr<PixelShader>(),
		-1,
		inventory_,
		std::make_shared<UI_Image>(
			image_Inventory.lock()->GetSize().ToVector2f(),
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			false,
			nullptr,
			std::weak_ptr<PixelShader>(),
			-1,
			image_Inventory
		),
		image_Item
	);
	uiInventory_->SetTransformData(
		{ 310.0f, 400.0f },
		0.0f,
		8.0f
	);
	uiInventory_->Init();

	// ��������UI��`��ł���悤�ɂ���
	RenderManager::GetInstance().AddRenderer2D(
		std::make_shared<UI_InventoryRenderer>(
			false,
			uiInventory_
		)
	);
	

	uiLayer_->AddUI(uiInventory_);
}

void InventorySystemScene::Update(void) {
	if (InputManager::GetInstance().IsTrgDown(KEY_INPUT_SPACE)) {
		SceneManager::GetInstance().SetNextScene(Scene::TYPE::UI_SYSTEM);
	}

	ImGui::Begin("InventoryMenu");
	
	// ImGui�̃E�B���h�E�̈ʒu��������
	if(ImGui::Button("DefaultPos")) ImGui::SetWindowPos({630.0f,220.0f});

	// �e�X���b�g�̏���ҏW�ł���悤�ɂ���
	for (int i = 0; i < Inventory<Item>::MAX_ITEM_SLOT_COUNT; i++) {
		if (ImGui::TreeNode(("Slot" + std::to_string(i)).c_str())) {
			// �A�C�e���̏����擾
			auto item = inventory_->GetItem(i);
			int itemID = item.expired() ? 0 : item.lock()->GetID();
			int itemCount = item.expired() ? 0 : item.lock()->GetCount();
			
			// ID�ƌ���`��
			ImGui::Text(("ItemID : " + std::to_string(itemID)).c_str());
			ImGui::Text(("ItemCount : " + std::to_string(itemCount)).c_str());
			
			// �A�C�e���̍폜
			if (ImGui::Button("Delete")) {
				inventory_->DeleteItem(i);
			}
			ImGui::TreePop();
		}
	}

	if (ImGui::InputInt("AddItemID", &addItemID_)) {
		
	}
	if (ImGui::Button("AddItem")) {
		// �w�肳�ꂽ�A�C�e�����C���x���g���ɒǉ�
		inventory_->AddItem(std::make_shared<Item>(addItemID_, 1));
	}

	ImGui::End();

	uiLayer_->Update();
}

void InventorySystemScene::Release(void) {
	uiLayer_->Release();
}

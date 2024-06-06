#include <DxLib.h>
#include "../SceneType.h"
#include "Menu/Inventory.h"
#include "../../GameObject/2D/UI/UI/Original/Inventory/UI_Inventory.h"
#include "Item/Item.h"
#include "../../Managers/ResourceManager.h"
#include "../../GameObject/2D/UI/UILayer/UILayer.h"
#include "../../GameObject/2D/UI/UILayer/UILayerInfo.h"
#include "InventorySystemScene.h"
#include "../../Library/imgui/imgui.h"
#include "../../Library/imgui/backends/imgui_impl_dx11.h"
#include "../../Library/imgui/backends/imgui_impl_win32.h"
#include "../../Library/imgui/misc/cpp/imgui_stdlib.h"
//#include "Item/ItemRenderer.h"

InventorySystemScene::InventorySystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::INVENTORY_SYSTEM;
}

void InventorySystemScene::Init(void) {
	uiLayer_ = std::make_unique<UILayer>();
	uiLayer_->LoadUILayer(UILayerInfo::TYPE::INVENTORY_SYSTEM_MENU);
	uiLayer_->Init();

	//auto& resourceManager = ResourceManager::GetInstance();

	// コンストラクタ経由でアイテム同士が同じかを比較する関数オブジェクトを渡す
	inventory_ = std::make_shared<Inventory<Item>>(&Item::Equal);
	inventory_->Init();

	// アイテムをセット
	inventory_->AddItem(std::make_shared<Item>(0, 100));
	inventory_->AddItem(std::make_shared<Item>(3, 100));
	inventory_->AddItem(std::make_shared<Item>(6, 100));
	inventory_->AddItem(std::make_shared<Item>(12, 100));
	inventory_->AddItem(std::make_shared<Item>(98, 100));
	inventory_->AddItem(std::make_shared<Item>(4, 100));
	inventory_->AddItem(std::make_shared<Item>(56, 100));
	inventory_->AddItem(std::make_shared<Item>(23, 100));
	inventory_->AddItem(std::make_shared<Item>(8, 100));

	//std::weak_ptr<Graphic> inventoryImage = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_INVENTORY").lock());

	//uiInventory_ = std::make_shared<UI_Inventory>(
	//	inventoryImage.lock()->GetSize().ToVector2f(),
	//	UI::UI_ORIGIN_TYPE::UP_LEFT,
	//	inventory_,
	//	std::make_shared<UI_Image>(
	//		inventoryImage.lock()->GetSize().ToVector2f(),
	//		UI::UI_ORIGIN_TYPE::UP_LEFT,
	//		inventoryImage
	//	)
	//);
	//uiInventory_->Init();
	//uiInventory_->SetTransformData(
	//	{ 500.0f, 400.0f },
	//	0.0f,
	//	{ 1.0f, 1.0f }
	//);

	//RenderManager::GetInstance().AddRenderer2D(
	//	std::make_shared<UI_InventoryRenderer>(
	//		false, 
	//		std::dynamic_pointer_cast<UI_Inventory>(uiInventory_)
	//	)
	//);
}

void InventorySystemScene::Update(void) {
	ImGui::Begin("InventoryMenu");

	uiLayer_->Update();

	ImGui::End();
}

void InventorySystemScene::Release(void) {
	uiLayer_->Release();
}

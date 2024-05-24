#include <DxLib.h>
#include "InventorySystemScene.h"
#include "../SceneType.h"
#include "Menu/Inventory.h"

InventorySystemScene::InventorySystemScene(void) {
	// ���̃V�[���̎�ނ��Z�b�g
	type_ = SCENE_TYPE::INVENTORY_SYSTEM;
}

void InventorySystemScene::Init(void) {
	inventory_ = std::make_unique<Inventory>();
	inventory_->Init();

	// �A�C�e�����Z�b�g
	inventory_->AddItem(std::make_shared<Item>(0, 100));
	inventory_->AddItem(std::make_shared<Item>(3, 100));
	inventory_->AddItem(std::make_shared<Item>(6, 100));
	inventory_->AddItem(std::make_shared<Item>(12, 100));
	inventory_->AddItem(std::make_shared<Item>(98, 100));
	inventory_->AddItem(std::make_shared<Item>(4, 100));
	inventory_->AddItem(std::make_shared<Item>(56, 100));
	inventory_->AddItem(std::make_shared<Item>(23, 100));
	inventory_->AddItem(std::make_shared<Item>(8, 100));
}

void InventorySystemScene::Update(void) {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		inventory_->AddItem(std::make_shared<Item>(0, 100));
	}
}

void InventorySystemScene::Draw(void) {
	// �C���x���g���̒��g��`��
	for (int i = 0; i < Inventory::MAX_ITEM_SLOT_COUNT; i++) {
		auto item = inventory_->GetItem(i);
		auto itemID = item.lock()->GetID();
		auto itemCount = item.lock()->GetCount();
		
		DrawFormatString(200 + (i * 32), 500, 0xFFFFFF, "%d", itemID);
		DrawFormatString(200 + (i * 32), 516, 0xFFFFFF, "%d", itemCount);
	}
}

void InventorySystemScene::Release(void) {

}

#include <DxLib.h>
#include "InventorySystemScene.h"
#include "../SceneType.h"
#include "Menu/Inventory.h"
#include "Menu/InventoryRenderer.h"
#include "Item/Item.h"
#include "Item/ItemRenderer.h"

InventorySystemScene::InventorySystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::INVENTORY_SYSTEM;
}

void InventorySystemScene::Init(void) {
	// コンストラクタ経由でアイテム同士が同じかを比較する関数オブジェクトを渡す
	inventory_ = std::make_shared<Inventory<Item>>(&Item::Equal);
	inventory_->Init();

	inventoryRenderer_ = std::make_unique<InventoryRenderer>(inventory_);

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

	item_ = std::make_unique<Item>(100,2);
	itemRenderer_ = std::make_unique<ItemRenderer>(item_);
}

void InventorySystemScene::Update(void) {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		inventory_->AddItem(std::make_shared<Item>(0, 100));
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		inventory_->AddItem(std::make_shared<Item>(98, 100));
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		inventory_->AddItem(std::make_shared<Item>(34, 100));
	}
}

void InventorySystemScene::Draw(void) {
	// インベントリの中身を描画
	inventoryRenderer_->Render();

	// アイテムの描画(テスト用)
	itemRenderer_->Render();
}

void InventorySystemScene::Release(void) {

}

#pragma once
#include <memory>
#include "../AbstractScene.h"

template <typename T>
class Inventory;
class UI_Inventory;
class UI_InventoryRenderer;
class Item;
class UILayer;
/// @brief [Unknown Level] プレイヤーのインベントリの処理
class InventorySystemScene : public AbstractScene {
public:
	InventorySystemScene(void);
	virtual ~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;

private:
	// このシーンのベースとなるUIのレイヤー
	std::unique_ptr<UILayer> uiLayer_;

	// インベントリ関係
	std::shared_ptr<Inventory<Item>> inventory_;
	std::shared_ptr<UI_Inventory> uiInventory_;
	std::unique_ptr<UI_InventoryRenderer> inventoryRenderer_;

	// 追加するアイテムを格納(ImGui用)
	int addItemID_;
};
#pragma once
#include <memory>
#include "../AbstractScene.h"

template <typename T>
class Inventory;
class InventoryRenderer;
class Item;
class ItemRenderer;

/// @brief [Unknown Level] プレイヤーのインベントリの処理
class InventorySystemScene : public AbstractScene {
public:
	InventorySystemScene(void);
	~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;

private:
	std::shared_ptr<Inventory<Item>> inventory_;
	std::unique_ptr<InventoryRenderer> inventoryRenderer_;
	std::shared_ptr<Item> item_;
	std::unique_ptr<ItemRenderer> itemRenderer_;
};

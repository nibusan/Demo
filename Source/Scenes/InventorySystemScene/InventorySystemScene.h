#pragma once
#include <memory>
#include "../AbstractScene.h"

template <typename T>
class Inventory;
template <typename T>
class InventoryRenderer;
class Item;

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
	std::unique_ptr<InventoryRenderer<std::shared_ptr<Inventory<Item>>>> inventoryRenderer_;

};


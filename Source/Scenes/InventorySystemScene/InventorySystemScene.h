#pragma once
#include <memory>
#include "../AbstractScene.h"

template <typename T>
class Inventory;
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
	std::unique_ptr<Inventory<Item>> inventory_;

};


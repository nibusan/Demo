#pragma once
#include <memory>
#include <DxLib.h>
#include "Inventory.h"

/// @brief インベントリを描画するためのクラス
/// @brief 今回はItemクラスを使用する前提で書いてます
class Item;
class InventoryRenderer {
public:
	InventoryRenderer(std::shared_ptr<Inventory<Item>> inventory);
	~InventoryRenderer(void) = default;

	// 描画する
	void Render(void);
private:
	// インベントリのデータ
	std::shared_ptr<Inventory<Item>> inventory_;
};
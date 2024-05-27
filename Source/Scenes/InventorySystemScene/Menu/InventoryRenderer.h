#pragma once
#include <memory>
#include <DxLib.h>
#include "Inventory.h"

/// @brief インベントリを描画するためのクラス
template <typename T>
class InventoryRenderer {
public:
	InventoryRenderer(std::shared_ptr<Inventory<T>> inventory);
	~InventoryRenderer(void) = default;

	// 描画する
	void Render(void);
private:
	// インベントリのデータ
	std::shared_ptr<Inventory<T>> inventory_;
};

template<typename T>
inline InventoryRenderer<T>::InventoryRenderer(std::shared_ptr<Inventory<T>> inventory) {
	inventory_ = inventory;
}

template<typename T>
inline void InventoryRenderer<T>::Render(void) {
	
	for (int i = 0; i < Inventory<T>::MAX_ITEM_SLOT_COUNT; i++) {
		DrawBox(
			300 + i * 100,
			300,
			350 + i * 100,
			350,
			0xFFFFFF,
			false
		);

		auto item = inventory_->GetItem(i).lock();
		if (item) {
			// 取得したアイテムが有効なら、そのアイテムに関する描画処理を行う
			// ここで例えばアイテムの名前や画像を描画できます
			DrawString(
				300 + i * 100,
				310,
				"Item",
				0xFFFFFF
			);
		}
	}
}
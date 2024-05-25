#pragma once
#include <array>
#include <memory>
#include "../Item/Item.h"
//#include "../MenuBase.h"

//class Inventory : public MenuBase {

/// @brief インベントリとして使用できるようにしたコンテナクラス
/// @tparam T アイテムとして格納したいクラス
template <typename T>
class Inventory {
public:
	// インベントリで保持できるアイテムスロットの数
	static constexpr int MAX_ITEM_SLOT_COUNT = 9;

private:
	// アイテムスロットを格納した配列
	std::array<std::shared_ptr<T>, MAX_ITEM_SLOT_COUNT> itemSlot_;

public:
	Inventory(void);
	~Inventory(void) = default;

	void Init(void);
	void Release(void);

	/// @brief アイテムを追加
	/// @param item アイテムのデータ
	void AddItem(std::shared_ptr<T> item);

	/// @brief 指定されたスロットのアイテムのデータを返す
	/// @param slot スロットのID
	/// @return スロットに入ってるアイテムのデータ
	std::weak_ptr<T> GetItem(int slot);

	/// @brief 指定されたスロットにアイテムをセット
	/// @param item アイテムのデータ
	/// @param slot	スロットのID
	/// @note 指定されたスロットにアイテムが入っている場合セットしません
	void SetItem(std::shared_ptr<T> item, int slot);
};

template <typename T>
Inventory<T>::Inventory(void) {
	//type_ = MENU_TYPE::INVENTORY_MENU;
}

template <typename T>
void Inventory<T>::Init(void) {

}

template <typename T>
void Inventory<T>::Release(void) {

}

template <typename T>
void Inventory<T>::AddItem(std::shared_ptr<T> item) {
	// 空のアイテムスロットを検索
	auto emptySlot = std::find(itemSlot_.begin(), itemSlot_.end(), nullptr);
	if (emptySlot != itemSlot_.end()) {
		// もしアイテムスロットが空だったらセットする
		(*emptySlot) = item;
	}
	else {
		// 同じアイテムが入ったスロットを検索
		auto sameItem_Slot = std::find_if(itemSlot_.begin(), itemSlot_.end(), [item](std::shared_ptr<Item> slotItem)->bool {
			return item->GetID() == slotItem->GetID();
			});
		if (sameItem_Slot != itemSlot_.end()) {
			// もし同じアイテムがあって、なおかつアイテムのスタック数が
			// 最大数じゃなかったらアイテムの個数を追加する
			(*sameItem_Slot)->AddCount(item->GetCount());
		}

	}
}

template <typename T>
std::weak_ptr<T> Inventory<T>::GetItem(int slot) {
	return itemSlot_[slot];
}

template <typename T>
void Inventory<T>::SetItem(std::shared_ptr<T> item, int slot) {
	// 指定されたスロットにアイテムが無かったらセットする
	if (itemSlot_[slot] == nullptr) itemSlot_[slot] = item;
}

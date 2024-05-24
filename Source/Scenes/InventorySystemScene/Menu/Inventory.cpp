#include <algorithm>
#include "Inventory.h"

Inventory::Inventory(void) {
	//type_ = MENU_TYPE::INVENTORY_MENU;
}

void Inventory::Init(void) {

}

void Inventory::Release(void) {

}

void Inventory::AddItem(std::shared_ptr<Item> item) {
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

std::weak_ptr<Item> Inventory::GetItem(int slot) {
	return itemSlot_[slot];
}

void Inventory::SetItem(std::shared_ptr<Item> item, int slot) {
	// 指定されたスロットにアイテムが無かったらセットする
	if (itemSlot_[slot] == nullptr) itemSlot_[slot] = item;
}

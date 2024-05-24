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
	// ��̃A�C�e���X���b�g������
	auto emptySlot = std::find(itemSlot_.begin(), itemSlot_.end(), nullptr);
	if (emptySlot != itemSlot_.end()) {
		// �����A�C�e���X���b�g���󂾂�����Z�b�g����
		(*emptySlot) = item;
	}
	else {
		// �����A�C�e�����������X���b�g������
		auto sameItem_Slot = std::find_if(itemSlot_.begin(), itemSlot_.end(), [item](std::shared_ptr<Item> slotItem)->bool {
			return item->GetID() == slotItem->GetID();
			});
		if (sameItem_Slot != itemSlot_.end()) {
			// ���������A�C�e���������āA�Ȃ����A�C�e���̃X�^�b�N����
			// �ő吔����Ȃ�������A�C�e���̌���ǉ�����
			(*sameItem_Slot)->AddCount(item->GetCount());
		}

	}
}

std::weak_ptr<Item> Inventory::GetItem(int slot) {
	return itemSlot_[slot];
}

void Inventory::SetItem(std::shared_ptr<Item> item, int slot) {
	// �w�肳�ꂽ�X���b�g�ɃA�C�e��������������Z�b�g����
	if (itemSlot_[slot] == nullptr) itemSlot_[slot] = item;
}

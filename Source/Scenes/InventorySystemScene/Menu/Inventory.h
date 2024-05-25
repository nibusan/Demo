#pragma once
#include <array>
#include <memory>
#include "../Item/Item.h"
//#include "../MenuBase.h"

//class Inventory : public MenuBase {

/// @brief �C���x���g���Ƃ��Ďg�p�ł���悤�ɂ����R���e�i�N���X
/// @tparam T �A�C�e���Ƃ��Ċi�[�������N���X
template <typename T>
class Inventory {
public:
	// �C���x���g���ŕێ��ł���A�C�e���X���b�g�̐�
	static constexpr int MAX_ITEM_SLOT_COUNT = 9;

private:
	// �A�C�e���X���b�g���i�[�����z��
	std::array<std::shared_ptr<T>, MAX_ITEM_SLOT_COUNT> itemSlot_;

public:
	Inventory(void);
	~Inventory(void) = default;

	void Init(void);
	void Release(void);

	/// @brief �A�C�e����ǉ�
	/// @param item �A�C�e���̃f�[�^
	void AddItem(std::shared_ptr<T> item);

	/// @brief �w�肳�ꂽ�X���b�g�̃A�C�e���̃f�[�^��Ԃ�
	/// @param slot �X���b�g��ID
	/// @return �X���b�g�ɓ����Ă�A�C�e���̃f�[�^
	std::weak_ptr<T> GetItem(int slot);

	/// @brief �w�肳�ꂽ�X���b�g�ɃA�C�e�����Z�b�g
	/// @param item �A�C�e���̃f�[�^
	/// @param slot	�X���b�g��ID
	/// @note �w�肳�ꂽ�X���b�g�ɃA�C�e���������Ă���ꍇ�Z�b�g���܂���
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

template <typename T>
std::weak_ptr<T> Inventory<T>::GetItem(int slot) {
	return itemSlot_[slot];
}

template <typename T>
void Inventory<T>::SetItem(std::shared_ptr<T> item, int slot) {
	// �w�肳�ꂽ�X���b�g�ɃA�C�e��������������Z�b�g����
	if (itemSlot_[slot] == nullptr) itemSlot_[slot] = item;
}

#pragma once
#include <array>
#include <memory>
#include <functional>
#include <algorithm>
//#include "../"

class InputManager;
/// @brief �C���x���g���Ƃ��Ďg�p���邱�Ƃɓ��������R���e�i�N���X
/// @brief �ǂ̃Q�[���ł������ɈڐA���Ďg����悤�ɐ݌v���܂���
/// @note ���̃N���X�ł̓f�[�^���i�[���鎞�̓X�}�[�g�|�C���^���g���܂�
/// @tparam T �A�C�e���Ƃ��Ċi�[�������N���X
template <typename T>
class Inventory {
public:
	// �C���x���g���ŕێ��ł���A�C�e���X���b�g�̐�
	static constexpr int MAX_ITEM_SLOT_COUNT = 9;

	Inventory(std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare);
	~Inventory(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief �A�C�e����ǉ�
	/// @param item �A�C�e���̃f�[�^
	void AddItem(const std::shared_ptr<T>& item);

	/// @brief �w�肳�ꂽ�X���b�g�̃A�C�e���̃f�[�^��Ԃ�
	/// @param slot �X���b�g��ID
	/// @return �X���b�g�ɓ����Ă�A�C�e���̃f�[�^
	std::weak_ptr<T> GetItem(int slot);

	/// @brief �w�肳�ꂽ�X���b�g�ɃA�C�e�����Z�b�g
	/// @param item �A�C�e���̃f�[�^
	/// @param slot	�X���b�g��ID
	/// @note �w�肳�ꂽ�X���b�g�ɃA�C�e���������Ă���ꍇ�Z�b�g���܂���
	void SetItem(std::shared_ptr<T> item, int slot);

private:
	// �A�C�e���X���b�g���i�[�����z��
	std::array<std::shared_ptr<T>, MAX_ITEM_SLOT_COUNT> itemSlot_;

	// ���ݑI�����Ă���A�C�e���X���b�g�̃C���f�b�N�X
	int selectingSlotIndex_;

	// �����A�C�e������r���邽�߂̊֐��I�u�W�F�N�g
	std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare_;

	/// @brief �S�ẴA�C�e���X���b�g���N���A����
	void ClearAllItemSlot(void);
};

template<typename T>
Inventory<T>::Inventory(std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare) : compare_(compare) {}

template <typename T>
void Inventory<T>::Init(void) {
	// �C���x���g�������Z�b�g����
	ClearAllItemSlot();

	selectingSlotIndex_ = 0;
}

template<typename T>
inline void Inventory<T>::Update(void) {
	
}

template <typename T>
void Inventory<T>::Release(void) {
	// �C���x���g�������Z�b�g����
	ClearAllItemSlot();
}

template <typename T>
void Inventory<T>::AddItem(const std::shared_ptr<T>& item) {
	// ��̃A�C�e���X���b�g������
	auto emptySlot = std::find(itemSlot_.begin(), itemSlot_.end(), nullptr);
	if (emptySlot != itemSlot_.end()) {
		// �����A�C�e���X���b�g���󂾂�����Z�b�g����
		(*emptySlot) = item;
	} else {
		// �����A�C�e�����������X���b�g������
		auto sameItem_Slot = std::find_if(itemSlot_.begin(), itemSlot_.end(), [this, item](const std::shared_ptr<T>& slotItem)->bool {
			// �\�߃A�C�e�����Œ�`���Ă�������r����֐����Ăяo����
			// �����A�C�e�����𔻒�
			return compare_(item, slotItem);
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

template<typename T>
void Inventory<T>::ClearAllItemSlot(void) {
	// �S�ẴA�C�e���X���b�g��nullptr��������
	// �����̎Q�ƃJ�E���^��0�ɂ��Ď����ŉ��������
	for (int i = 0; i < MAX_ITEM_SLOT_COUNT; i++) {
		itemSlot_[i] = nullptr;
	}
}

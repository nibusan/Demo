#pragma once
#include <memory>
#include <DxLib.h>
#include "Inventory.h"

/// @brief �C���x���g����`�悷�邽�߂̃N���X
template <typename T>
class InventoryRenderer {
public:
	InventoryRenderer(std::shared_ptr<Inventory<T>> inventory);
	~InventoryRenderer(void) = default;

	// �`�悷��
	void Render(void);
private:
	// �C���x���g���̃f�[�^
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
			// �擾�����A�C�e�����L���Ȃ�A���̃A�C�e���Ɋւ���`�揈�����s��
			// �����ŗႦ�΃A�C�e���̖��O��摜��`��ł��܂�
			DrawString(
				300 + i * 100,
				310,
				"Item",
				0xFFFFFF
			);
		}
	}
}
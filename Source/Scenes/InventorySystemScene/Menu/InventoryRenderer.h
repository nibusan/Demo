#pragma once
#include <memory>
#include <DxLib.h>
#include "Inventory.h"

/// @brief �C���x���g����`�悷�邽�߂̃N���X
/// @brief �����Item�N���X���g�p����O��ŏ����Ă܂�
class Item;
class InventoryRenderer {
public:
	InventoryRenderer(std::shared_ptr<Inventory<Item>> inventory);
	~InventoryRenderer(void) = default;

	// �`�悷��
	void Render(void);
private:
	// �C���x���g���̃f�[�^
	std::shared_ptr<Inventory<Item>> inventory_;
};
#pragma once
#include <array>
#include <memory>
#include "../Item/Item.h"
//#include "../MenuBase.h"

//class Inventory : public MenuBase {
class Inventory {
public:
	// �C���x���g���ŕێ��ł���A�C�e���X���b�g�̐�
	static constexpr int MAX_ITEM_SLOT_COUNT = 9;

private:
	// �A�C�e���X���b�g���i�[�����z��
	std::array<std::shared_ptr<Item>, MAX_ITEM_SLOT_COUNT> itemSlot_;

public:
	Inventory(void);
	~Inventory(void) = default;

	void Init(void);
	void Release(void);

	/// @brief �A�C�e����ǉ�
	/// @param item �A�C�e���̃f�[�^
	void AddItem(std::shared_ptr<Item> item);

	/// @brief �w�肳�ꂽ�X���b�g�̃A�C�e���̃f�[�^��Ԃ�
	/// @param slot �X���b�g��ID
	/// @return �X���b�g�ɓ����Ă�A�C�e���̃f�[�^
	std::weak_ptr<Item> GetItem(int slot);

	/// @brief �w�肳�ꂽ�X���b�g�ɃA�C�e�����Z�b�g
	/// @param item �A�C�e���̃f�[�^
	/// @param slot	�X���b�g��ID
	/// @note �w�肳�ꂽ�X���b�g�ɃA�C�e���������Ă���ꍇ�Z�b�g���܂���
	void SetItem(std::shared_ptr<Item> item, int slot);
};

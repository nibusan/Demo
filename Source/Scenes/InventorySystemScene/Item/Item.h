#pragma once
#include <memory>

/// @brief �C���x���g���Ɋi�[���邽�߂̃e�X�g�p�N���X
class Item {
public:
	// �A�C�e���摜�̉��̕�����
	static constexpr int ITEM_NUM_X = 8;

	// �A�C�e���摜�̏c�̕�����
	static constexpr int ITEM_NUM_Y = 8;

	// �A�C�e��ID�̍ő吔
	static constexpr int MAX_ITEM_ID = ITEM_NUM_X * ITEM_NUM_Y - 1;

	Item(void);
	~Item(void) = default;

	/// @brief �R���X�g���N�^
	/// @param id �A�C�e��ID
	/// @param count �A�C�e���̌�
	Item(int id, int count);

	/// @brief �A�C�e��ID���Z�b�g
	/// @param id �A�C�e��ID
	void SetID(int id);

	/// @brief �A�C�e��ID��Ԃ� 
	/// @return �A�C�e��ID
	int GetID(void) const;

	/// @brief �A�C�e���̌��ɂ𑝂₷
	/// @param count ���₷��
	void AddCount(int count);

	/// @brief �A�C�e���̌����Z�b�g
	/// @param count ��
	void SetCount(int count);

	/// @brief �A�C�e���̐���Ԃ� 
	/// @return �A�C�e���̌�
	int GetCount(void) const;

	/// @brief ��̃A�C�e�����������ǂ����𔻒肷��
	/// @param item1 ��ڂ̃A�C�e��
	/// @param item2 ��ڂ̃A�C�e��
	/// @return �������ǂ���
	static bool Equal(const std::shared_ptr<Item>& item1, const std::shared_ptr<Item>& item2);
private:
	// �A�C�e��ID
	int id_;

	// �A�C�e���̌�
	int count_;
};
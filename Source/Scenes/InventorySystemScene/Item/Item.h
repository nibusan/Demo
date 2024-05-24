#pragma once

class Item {
public:
	Item(void);
	Item(int id, int count);
	~Item(void) = default;

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

private:
	// �A�C�e��ID
	int id_;

	// �A�C�e���̌�
	int count_;
};
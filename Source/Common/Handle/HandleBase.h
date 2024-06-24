#pragma once

/// @brief 
class HandleBase {
public:
	HandleBase(void);
	virtual ~HandleBase(void) = default;

	/// @brief �n���h��ID��Ԃ�
	/// @return �n���h��ID
	[[nodiscard]] int GetHandle(void) const;

	/// @brief �n���h��ID���Z�b�g
	/// @param handle �n���h��ID
	void SetHandle(int handle);

	/// @brief �f�X�g���N�^���Ă΂ꂽ�ۂɎ����I�Ƀn���h�����폜���邩��Ԃ�
	/// @return �폜���邩�̃t���O
	[[nodiscard]] bool IsAutoDeleteHandle(void) const;

	/// @brief �f�X�g���N�^���Ă΂ꂽ�ۂɎ����I�Ƀn���h�����폜���邩���Z�b�g
	/// @param flag �폜���邩�̃t���O
	void SetIsAutoDeleteHandle(bool flag);

protected:
	//�n���h��ID
	int handle_;

	//�f�X�g���N�^���Ă΂ꂽ�Ƃ��Ƀn���h����j�����邩���Ǘ�(true:�����j��)
	bool isAutoDeleteHandle_;
};

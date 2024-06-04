#pragma once
#include "../GameObject3D.h"

/// @brief �J�����̃N���X�ł�
class Camera : public GameObject3D {
public:
	// �J�����̏��
	enum class STATE {
		NORMAL,		// �ʏ탂�[�h
		FIXED_POINT	// ��_�J����
	};

	Camera(void) = default;
	~Camera(void) = default;

	/// @brief �J�����̏�Ԃ�ύX����
	/// @param state �J�����̏��
	void ChangeMode(STATE state);

	/// @brief �J�����̏����Z�b�g(���t���[���ĂԕK�v����) 
	void SetBeforeDraw(void);
private:
	// ���݂̃J�����̏��
	STATE state_;

	void Init_GameObject3D(void) override;
	void Update_GameObject3D(void) override;
	void Release_GameObject3D(void) override;

	/// @brief �J�����̈ړ�����(�p�x���ς���܂�)
	void Move(void);
};


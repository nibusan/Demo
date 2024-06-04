#include "../../../Utility/Utility.h"
#include "../../../Managers/InputManager.h"
#include "Camera.h"

void Camera::ChangeMode(STATE state) {
	state_ = state;
}

void Camera::SetBeforeDraw(void) {
	// �J�����̐ݒ�
	SetupCamera_Perspective(1.0472f);
	SetCameraNearFar(0.1f, 1000.0f);

	// �J�����̐ݒ�
	SetCameraPositionAndAngle(
		{ transform_.currentPos_.x, transform_.currentPos_.y, transform_.currentPos_.z },
		transform_.currentRot_.x,
		transform_.currentRot_.y,
		transform_.currentRot_.z
	);
}

void Camera::Init_GameObject3D(void) {
	state_ = STATE::NORMAL;
}

void Camera::Update_GameObject3D(void) {
	// ��Ԃɂ���čX�V������ς���
	switch (state_) {
	case Camera::STATE::NORMAL:
		Move();
		break;
	case Camera::STATE::FIXED_POINT:
		// ��_�J�����͌Œ肷��̂ŉ������Ȃ�
		break;
	default:
		break;
	}
}

void Camera::Release_GameObject3D(void) {

}

void Camera::Move(void) {
	// ���͌��m�p
	auto& inputManager = InputManager::GetInstance();

	float movePow = 0.1f;

	// WASD�ŃJ�����̈ʒu��ς���
	Vector3<float> dir = {};
	if (inputManager.IsNew(KEY_INPUT_W) == true) dir = { 0.0f,0.0f,1.0f };
	if (inputManager.IsNew(KEY_INPUT_A) == true) dir = { -1.0f,0.0f,0.0f };
	if (inputManager.IsNew(KEY_INPUT_S) == true) dir = { 0.0f,0.0f,-1.0f };
	if (inputManager.IsNew(KEY_INPUT_D) == true) dir = { 1.0f,0.0f,0.0f };

	if (!Utility::EqualsVZero(dir.ToVector3d())) {
		// XYZ�̉�]�s��
		// XZ���ʈړ��ɂ���ꍇ�́AXZ�̉�]���l�����Ȃ��悤�ɂ���
		MATRIX mat = MGetIdent();

		mat = MMult(mat, MGetRotX(transform_.currentRot_.x));
		mat = MMult(mat, MGetRotY(transform_.currentRot_.y));
		mat = MMult(mat, MGetRotZ(transform_.currentRot_.z));

		// ��]�s����g�p���āA�x�N�g������]������
		VECTOR moveDir = VTransform({ dir.x,dir.y,dir.z }, mat);

		// �����~�X�s�[�h�ňړ��ʂ�����āA���W�ɑ����Ĉړ�
		transform_.localPos_ = transform_.localPos_ + Vector3<float>(moveDir.x,moveDir.y,moveDir.z) * movePow;
	}

	if (inputManager.IsNew(KEY_INPUT_Q)) transform_.localPos_.y += movePow;
	if (inputManager.IsNew(KEY_INPUT_E)) transform_.localPos_.y -= movePow;

	// ���L�[�ŃJ�����̊p�x��ς���
	float rotPow = 1.0f * DX_PI_F / 180.0f;

	if (inputManager.IsNew(KEY_INPUT_DOWN)) transform_.localRot_.x += rotPow;
	if (inputManager.IsNew(KEY_INPUT_UP)) transform_.localRot_.x -= rotPow;
	if (inputManager.IsNew(KEY_INPUT_RIGHT)) transform_.localRot_.y += rotPow;
	if (inputManager.IsNew(KEY_INPUT_LEFT)) transform_.localRot_.y -= rotPow;
}

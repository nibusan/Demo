#include "../../../Utility/Utility.h"
#include "../../../Managers/InputManager.h"
#include "Camera.h"

void Camera::ChangeMode(STATE state) {
	state_ = state;
}

void Camera::SetBeforeDraw(void) {
	// カメラの設定
	SetupCamera_Perspective(1.0472f);
	SetCameraNearFar(0.1f, 1000.0f);

	// カメラの設定
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
	// 状態によって更新処理を変える
	switch (state_) {
	case Camera::STATE::NORMAL:
		Move();
		break;
	case Camera::STATE::FIXED_POINT:
		// 定点カメラは固定するので何もしない
		break;
	default:
		break;
	}
}

void Camera::Release_GameObject3D(void) {

}

void Camera::Move(void) {
	// 入力検知用
	auto& inputManager = InputManager::GetInstance();

	float movePow = 0.1f;

	// WASDでカメラの位置を変える
	Vector3<float> dir = {};
	if (inputManager.IsNew(KEY_INPUT_W) == true) dir = { 0.0f,0.0f,1.0f };
	if (inputManager.IsNew(KEY_INPUT_A) == true) dir = { -1.0f,0.0f,0.0f };
	if (inputManager.IsNew(KEY_INPUT_S) == true) dir = { 0.0f,0.0f,-1.0f };
	if (inputManager.IsNew(KEY_INPUT_D) == true) dir = { 1.0f,0.0f,0.0f };

	if (!Utility::EqualsVZero(dir.ToVector3d())) {
		// XYZの回転行列
		// XZ平面移動にする場合は、XZの回転を考慮しないようにする
		MATRIX mat = MGetIdent();

		mat = MMult(mat, MGetRotX(transform_.currentRot_.x));
		mat = MMult(mat, MGetRotY(transform_.currentRot_.y));
		mat = MMult(mat, MGetRotZ(transform_.currentRot_.z));

		// 回転行列を使用して、ベクトルを回転させる
		VECTOR moveDir = VTransform({ dir.x,dir.y,dir.z }, mat);

		// 方向×スピードで移動量を作って、座標に足して移動
		transform_.localPos_ = transform_.localPos_ + Vector3<float>(moveDir.x,moveDir.y,moveDir.z) * movePow;
	}

	if (inputManager.IsNew(KEY_INPUT_Q)) transform_.localPos_.y += movePow;
	if (inputManager.IsNew(KEY_INPUT_E)) transform_.localPos_.y -= movePow;

	// 矢印キーでカメラの角度を変える
	float rotPow = 1.0f * DX_PI_F / 180.0f;

	if (inputManager.IsNew(KEY_INPUT_DOWN)) transform_.localRot_.x += rotPow;
	if (inputManager.IsNew(KEY_INPUT_UP)) transform_.localRot_.x -= rotPow;
	if (inputManager.IsNew(KEY_INPUT_RIGHT)) transform_.localRot_.y += rotPow;
	if (inputManager.IsNew(KEY_INPUT_LEFT)) transform_.localRot_.y -= rotPow;
}

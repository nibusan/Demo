#pragma once
#include "../Transform.h"

/// @brief 3D�ł�Transform�N���X�ł�
class Transform3D : public Transform<Vector3<float>> {
public:
	Transform3D(void) : parentRot_({}), localRot_({}), currentRot_({}), parentScl_({}), localScl_({}), currentScl_({}) {
		parentPos_ = {};
		localPos_ = {};
		currentPos_ = {};
	}
	~Transform3D(void) = default;

	// �p�x
	Vector3<float> parentRot_;
	Vector3<float> localRot_;
	Vector3<float> currentRot_;

	// �X�P�[���l
	Vector3<float> parentScl_;
	Vector3<float> localScl_;
	Vector3<float> currentScl_;
};
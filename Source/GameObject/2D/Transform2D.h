#pragma once
#include "../Transform.h"

/// @brief 2D�ł�Transform�N���X�ł�
class Transform2D : public Transform<Vector2<float>> {
public:
	Transform2D(void) : parentRot_(0.0f), localRot_(0.0f), currentRot_(0.0f), parentScl_(0.0f), localScl_(0.0f), currentScl_(0.0f) {
		parentPos_ = {};
		localPos_ = {};
		currentPos_ = {};
	}
	~Transform2D(void) = default;

	// �p�x
	float parentRot_;
	float localRot_;
	float currentRot_;

	// �X�P�[���l
	float parentScl_;
	float localScl_;
	float currentScl_;
};
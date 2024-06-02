#pragma once
#include "Transform.h"

/// @brief 2D版のTransformクラスです
class Transform2D : public Transform<Vector2<float>> {
public:
	Transform2D(void) : parentRot_(0.0f), localRot_(0.0f), currentRot_(0.0f) {
		parentPos_ = {};
		parentScl_ = {};
		localPos_ = {};
		localScl_ = {};
		currentPos_ = {};
		currentScl_ = {};
	}
	~Transform2D(void) = default;

	// 角度
	float parentRot_;
	float localRot_;
	float currentRot_;
};
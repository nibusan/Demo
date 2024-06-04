#pragma once
#include "../Transform.h"

/// @brief 3D版のTransformクラスです
class Transform3D : public Transform<Vector3<float>> {
public:
	Transform3D(void) : parentRot_({}), localRot_({}), currentRot_({}), parentScl_({}), localScl_({}), currentScl_({}) {
		parentPos_ = {};
		localPos_ = {};
		currentPos_ = {};
	}
	~Transform3D(void) = default;

	// 角度
	Vector3<float> parentRot_;
	Vector3<float> localRot_;
	Vector3<float> currentRot_;

	// スケール値
	Vector3<float> parentScl_;
	Vector3<float> localScl_;
	Vector3<float> currentScl_;
};
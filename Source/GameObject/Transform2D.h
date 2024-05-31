#pragma once
#include "Transform.h"

/// @brief 2D版のTransformクラスです
class Transform2D : public Transform<Vector2<float>> {
public:
	// 角度
	float parentRot_;
	float localRot_;
	float currentRot_;
};
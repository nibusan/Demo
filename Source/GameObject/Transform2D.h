#pragma once
#include "Transform.h"

/// @brief 2D”Å‚ÌTransformƒNƒ‰ƒX‚Å‚·
class Transform2D : public Transform<Vector2<float>> {
public:
	// Šp“x
	float parentRot_;
	float localRot_;
	float currentRot_;
};
#pragma once
#include "Transform.h"

class Transform2D : public Transform<Vector2<float>> {
public:
	float parentRot_;
	float localRot_;
	float currentRot_;
};
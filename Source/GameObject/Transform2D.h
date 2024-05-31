#pragma once
#include "Transform.h"

/// @brief 2D�ł�Transform�N���X�ł�
class Transform2D : public Transform<Vector2<float>> {
public:
	// �p�x
	float parentRot_;
	float localRot_;
	float currentRot_;
};
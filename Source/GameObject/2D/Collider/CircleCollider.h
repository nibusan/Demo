#pragma once
#include "AbstractCollider.h"

/// @brief �~�̃R���C�_�[�N���X�ł�
class CircleCollider : public AbstractCollider {
public:
	CircleCollider(void);
	~CircleCollider(void) override = default;

	CircleCollider(const Vector2<float>& centerPos, float radius);

	bool IsContains(const Vector2<float>& point) const override;
private:
	// ���a
	float radius_;;

};


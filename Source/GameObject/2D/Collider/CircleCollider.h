#pragma once
#include "AbstractCollider.h"

/// @brief 円のコライダークラスです
class CircleCollider : public AbstractCollider {
public:
	CircleCollider(void);
	~CircleCollider(void) override = default;

	CircleCollider(const Vector2<float>& centerPos, float radius);

	bool IsContains(const Vector2<float>& point) const override;
private:
	// 半径
	float radius_;;

};


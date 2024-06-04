#pragma once
#include "../../../Common/Vector2.h"
#include "Collider_Info.h"

class AbstractCollider {
public:
	AbstractCollider(void);
	virtual ~AbstractCollider(void) = default;

	AbstractCollider(const Vector2<float>& centerPos);

	/// @brief 点がこのコライダーの中に入ってるかを判定
	/// @param point 点の座標
	/// @return 衝突してるかどうか
	virtual bool IsContains(const Vector2<float>& point) const = 0;
protected:
	// 中心座標
	Vector2<float> centerPos_;

	// コライダーの種類
	Collider_Info::TYPE type_;
};
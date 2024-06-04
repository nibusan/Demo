#include "CircleCollider.h"

CircleCollider::CircleCollider(void) : radius_(0.0f) {
	type_ = Collider_Info::TYPE::CIRCLE;
}

CircleCollider::CircleCollider(const Vector2<float>& centerPos, float radius) : AbstractCollider(centerPos_), radius_(radius) {
	type_ = Collider_Info::TYPE::CIRCLE;
}

bool CircleCollider::IsContains(const Vector2<float>& point) const {
	return ((centerPos_.x - point.x) * (centerPos_.x - point.x)) + ((centerPos_.y - point.y) * (centerPos_.y - point.y)) < radius_* radius_;
}

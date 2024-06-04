#include <cmath>
#include "RectCollider.h"

RectCollider::RectCollider(void) : size_(Vector2<float>()) {
	type_ = Collider_Info::TYPE::RECT;
}

RectCollider::RectCollider(const Vector2<float>& centerPos, const Vector2<float>& size) : AbstractCollider(centerPos), size_(size) {
	type_ = Collider_Info::TYPE::RECT;
}

bool RectCollider::IsContains(const Vector2<float>& point) const {
	return std::abs(centerPos_.x - point.x) < size_.x && 
		std::abs(centerPos_.y - point.y) < size_.y;
}

const Vector2<float>& RectCollider::GetSize(void) const {
	return size_;
}

#include "AbstractCollider.h"

AbstractCollider::AbstractCollider(void) : centerPos_(Vector2<float>()), type_(Collider_Info::TYPE::NONE) {}

AbstractCollider::AbstractCollider(const Vector2<float>& centerPos) : centerPos_(centerPos), type_(Collider_Info::TYPE::NONE) {}

const Vector2<float>& AbstractCollider::GetCenterPos(void) const {
	return centerPos_;
}

void AbstractCollider::SetCenterPos(const Vector2<float>& centerPos) {
	centerPos_ = centerPos;
}

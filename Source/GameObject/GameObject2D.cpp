#include <DxLib.h>
#include "GameObject2D.h"

void GameObject2D::Init_GameObject(void) {

}

void GameObject2D::Update_GameObject(void) {

}

void GameObject2D::Release_GameObject(void) {

}

const Transform<Vector2<float>>& GameObject2D::GetTransform(void) const {
	return transform_;
}

void GameObject2D::SetTransformData(
	const Vector2<float>& pos, 
	const Vector2<float>& localPos, 
	const Vector2<float>& rot, 
	const Vector2<float>& localRot, 
	const Vector2<float>& scl, 
	const Vector2<float>& localScl
) {
	transform_.pos_ = pos;
	transform_.localPos_ = localPos;
	transform_.rot_ = rot;
	transform_.localRot_ = localRot;
	transform_.scl_ = scl;
	transform_.localScl_ = localScl;
}

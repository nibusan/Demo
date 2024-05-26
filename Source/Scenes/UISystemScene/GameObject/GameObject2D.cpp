#include <DxLib.h>
#include "GameObject2D.h"

GameObject2D::GameObject2D(const Vector2<float>& pos, const Vector2<float>& rot, const Vector2<float>& scl) {
	// äÓëbèÓïÒÇÉZÉbÉg
	transform_.pos_ = pos;
	transform_.rot_ = rot;
	transform_.scl_ = scl;
}

void GameObject2D::Init_GameObject(void) {

}

void GameObject2D::Update_GameObject(void) {

}

void GameObject2D::Draw_GameObject(void) {
	DrawBox(transform_.pos_.x - 30, transform_.pos_.y - 30, transform_.pos_.x + 30, transform_.pos_.y + 30, 0xFFFFFF, false);
}

void GameObject2D::Release_GameObject(void) {

}

const Transform<Vector2<float>>& GameObject2D::GetTransform(void) const {
	return transform_;
}

void GameObject2D::SetTransform(const Transform<Vector2<float>>& transform) {
	transform_ = transform;
}
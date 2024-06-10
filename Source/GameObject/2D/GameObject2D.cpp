#include <DxLib.h>
#include <stack>
#include <utility>
#include "GameObject2D.h"

void GameObject2D::Init_GameObject(void) {
	Init_GameObject2D();
	CalculateTransform2D();
}

void GameObject2D::Update_GameObject(void) {
	// Transformの更新処理
	CalculateTransform2D();

	Update_GameObject2D();
}

void GameObject2D::Release_GameObject(void) {
	Release_GameObject2D();
	collider_ = nullptr;
}

void GameObject2D::CalculateTransform2D(void) {
	if (parent_.lock() != nullptr) {
		// 親オブジェクトが存在する場合の計算処理
		const std::weak_ptr<GameObject2D>& parent_GameObject2D = std::dynamic_pointer_cast<GameObject2D>(parent_.lock());
		const auto& parentTransform = parent_GameObject2D.lock()->GetTransform();
		transform_.parentPos_ = parentTransform.currentPos_;
		transform_.parentRot_ = parentTransform.currentRot_;
		transform_.parentScl_ = parentTransform.currentScl_;
		transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
		transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
		transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
	}
	else {
		// 親オブジェクトが存在しない場合の計算処理
		transform_.localPos_ = transform_.parentPos_ + transform_.localPos_;
		transform_.localRot_ = transform_.parentRot_ + transform_.localRot_;
		transform_.localScl_ = transform_.parentScl_ + transform_.localScl_;
		transform_.parentPos_ = Vector2<float>();
		transform_.parentRot_ = 0.0f;
		transform_.parentScl_ = 0.0f;
		transform_.currentPos_ = transform_.localPos_;
		transform_.currentRot_ = transform_.localRot_;
		transform_.currentScl_ = transform_.localScl_;
	}
}

void GameObject2D::SetParent(std::weak_ptr<GameObject> parent) {
	parent_ = parent;

	// 親をセットした際に座標などがバグらないように計算する
	const std::weak_ptr<GameObject2D>& parent_GameObject2D = std::dynamic_pointer_cast<GameObject2D>(parent_.lock());
	const auto& parentTransform = parent_GameObject2D.lock()->GetTransform();
	transform_.parentPos_ = parentTransform.currentPos_;
	transform_.parentRot_ = parentTransform.currentRot_;
	transform_.parentScl_ = parentTransform.currentScl_;
	transform_.localPos_ = transform_.currentPos_ - transform_.parentPos_;
	transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
	transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
	transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
	CalculateTransform2D();

	// 子オブジェクトが存在する場合は子オブジェクトの親の値を更新する
	for (const auto& child : childs_) {
		auto& childTransform = std::dynamic_pointer_cast<GameObject2D>(child)->GetTransform();
		childTransform.parentPos_ = transform_.currentPos_;
		childTransform.parentRot_ = transform_.currentRot_;
		childTransform.parentScl_ = transform_.currentScl_;
	}
}

void GameObject2D::AddChild(std::shared_ptr<GameObject> child) {
	child->SetParent(shared_from_this());
	childs_.emplace_back(child);

}

Transform2D& GameObject2D::GetTransform(void) {
	return transform_;
}

void GameObject2D::SetTransformData(
	const Vector2<float>& localPos, 
	float localRot, 
	float localScl
) {
	transform_.localPos_ = localPos;
	transform_.localRot_ = localRot;
	transform_.localScl_ = localScl;

	transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
	transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
	transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
}

std::weak_ptr<AbstractCollider> GameObject2D::GetCollider(void) const {
	return collider_;
}

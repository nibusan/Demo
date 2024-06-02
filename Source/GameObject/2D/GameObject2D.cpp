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
}

void GameObject2D::CalculateTransform2D(void) {
	if (parent_.lock() != nullptr) {
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
		transform_.localPos_ = transform_.parentPos_ + transform_.localPos_;
		transform_.localRot_ = transform_.parentRot_ + transform_.localRot_;
		transform_.localScl_ = transform_.parentScl_ + transform_.localScl_;
		transform_.parentPos_ = Vector2<float>();
		transform_.parentRot_ = 0.0f;
		transform_.parentScl_ = Vector2<float>();
		transform_.currentPos_ = transform_.localPos_;
		transform_.currentRot_ = transform_.localRot_;
		transform_.currentScl_ = transform_.localScl_;
	}
}

void GameObject2D::SetParent(std::weak_ptr<GameObject> parent) {
	parent_ = parent;

	//CalculateTransform2D();

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

	for (const auto& child : childs_) {
		auto& childTransform = std::dynamic_pointer_cast<GameObject2D>(child)->GetTransform();
		childTransform.parentPos_ = transform_.currentPos_;
		childTransform.parentRot_ = transform_.currentRot_;
		childTransform.parentScl_ = transform_.currentScl_;
	}
}

void GameObject2D::DeleteChild(void) {
	childs_.clear();
}

void GameObject2D::DeleteKankei(void) {
	parent_.reset();
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
	const Vector2<float>& localScl
) {
	transform_.localPos_ = localPos;
	transform_.localRot_ = localRot;
	transform_.localScl_ = localScl;

	transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
	transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
	transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
}

Vector2<float> GameObject2D::GetWorldPos(void) {
	//std::weak_ptr<GameObject2D> parent = std::dynamic_pointer_cast<GameObject2D>(GetParent());
	
	// 計算済みの座標を格納
	Vector2<float> calcPos = {};
	
	// 親座標を格納していくスタック(座標、ローカル座標)
	// 一番上の親から計算していくのでスタックを利用してます
	//std::stack<std::pair<Vector2<float>, Vector2<float>>> parentPosStack_;
	//while (parent.lock() != nullptr) {
	//	const auto& transform = parent.lock()->GetTransform();
	//	parentPosStack_.push({ transform.pos_, transform.localPos_ });
	//	parent = std::dynamic_pointer_cast<GameObject2D>(parent.lock()->GetParent().lock());
	//}
	
	return Vector2<float>();
}

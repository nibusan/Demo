#include <DxLib.h>
#include <stack>
#include <utility>
#include "GameObject3D.h"

void GameObject3D::Init_GameObject(void) {
	Init_GameObject3D();
	CalculateTransform3D();
}

void GameObject3D::Update_GameObject(void) {
	// TransformÇÃçXêVèàóù
	CalculateTransform3D();

	Update_GameObject3D();
}

void GameObject3D::Release_GameObject(void) {
	Release_GameObject3D();
}

void GameObject3D::CalculateTransform3D(void) {
	if (parent_.lock() != nullptr) {
		const std::weak_ptr<GameObject3D>& parent_GameObject3D = std::dynamic_pointer_cast<GameObject3D>(parent_.lock());
		const auto& parentTransform = parent_GameObject3D.lock()->GetTransform();
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
		transform_.parentPos_ = Vector3<float>();
		transform_.parentRot_ = Vector3<float>();
		transform_.parentScl_ = Vector3<float>();
		transform_.currentPos_ = transform_.localPos_;
		transform_.currentRot_ = transform_.localRot_;
		transform_.currentScl_ = transform_.localScl_;
	}
}

void GameObject3D::SetParent(std::weak_ptr<GameObject> parent) {
	parent_ = parent;

	//CalculateTransform3D();

	const std::weak_ptr<GameObject3D>& parent_GameObject3D = std::dynamic_pointer_cast<GameObject3D>(parent_.lock());
	const auto& parentTransform = parent_GameObject3D.lock()->GetTransform();
	transform_.parentPos_ = parentTransform.currentPos_;
	transform_.parentRot_ = parentTransform.currentRot_;
	transform_.parentScl_ = parentTransform.currentScl_;
	transform_.localPos_ = transform_.currentPos_ - transform_.parentPos_;
	transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
	transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
	transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
	CalculateTransform3D();

	for (const auto& child : childs_) {
		auto& childTransform = std::dynamic_pointer_cast<GameObject3D>(child)->GetTransform();
		childTransform.parentPos_ = transform_.currentPos_;
		childTransform.parentRot_ = transform_.currentRot_;
		childTransform.parentScl_ = transform_.currentScl_;
	}
}

void GameObject3D::AddChild(std::shared_ptr<GameObject> child) {
	child->SetParent(shared_from_this());
	childs_.emplace_back(child);

}

Transform3D& GameObject3D::GetTransform(void) {
	return transform_;
}

void GameObject3D::SetTransformData(
	const Vector3<float>& localPos, 
	const Vector3<float>& localRot, 
	const Vector3<float>& localScl
) {
	transform_.localPos_ = localPos;
	transform_.localRot_ = localRot;
	transform_.localScl_ = localScl;

	transform_.currentPos_ = transform_.parentPos_ + transform_.localPos_;
	transform_.currentRot_ = transform_.parentRot_ + transform_.localRot_;
	transform_.currentScl_ = transform_.parentScl_ * transform_.localScl_;
}
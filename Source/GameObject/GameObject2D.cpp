#include <DxLib.h>
#include <stack>
#include <utility>
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

Vector2<float> GameObject2D::GetWorldPos(void) {
	std::weak_ptr<GameObject2D> parent = std::dynamic_pointer_cast<GameObject2D>(GetParent().lock());
	
	// �v�Z�ς݂̍��W���i�[
	Vector2<float> calcPos = {};
	
	// �e���W���i�[���Ă����X�^�b�N(���W�A���[�J�����W)
	// ��ԏ�̐e����v�Z���Ă����̂ŃX�^�b�N�𗘗p���Ă܂�
	std::stack<std::pair<Vector2<float>, Vector2<float>>> parentPosStack_;
	while (parent.lock() != nullptr) {
		const auto& transform = parent.lock()->GetTransform();
		parentPosStack_.push({ transform.pos_, transform.localPos_ });
		parent = std::dynamic_pointer_cast<GameObject2D>(parent.lock()->GetParent().lock());
	}
	
	return Vector2<float>();
}

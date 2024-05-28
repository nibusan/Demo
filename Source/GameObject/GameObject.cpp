#include "GameObject.h"

GameObject::GameObject(void) : isActive_(true) {

}

void GameObject::Init(void) {
	Init_GameObject();

	// �f�t�H���g�ŃA�N�e�B�u��Ԃɂ���
	SetActive(true);
}

void GameObject::Update(void) {
	// �A�N�e�B�u����Ȃ�������X�V���������Ȃ�
	if (!IsActive()) return;

	Update_GameObject();
}

void GameObject::Release(void) {
	Release_GameObject();
}

bool GameObject::IsActive(void) const {
    return isActive_;
}

void GameObject::SetActive(bool flag) {
	isActive_ = flag;
}

const std::weak_ptr<GameObject>& GameObject::GetParent(void) const {
	return parent_;
}

void GameObject::SetParent(const std::shared_ptr<GameObject>& parent) {
	parent_ = parent;
}

const std::vector<std::shared_ptr<GameObject>> GameObject::GetChilds(void) const {
    return childs_;
}

void GameObject::AddChild(const std::shared_ptr<GameObject>& child) {
	childs_.emplace_back(child);
}
#include "GameObject.h"

GameObject::GameObject(void) : 
isActive_(true),
isDeleted_(false) {}

void GameObject::Init(void) {
	//����������
	Init_GameObject();

	// �f�t�H���g�ŃA�N�e�B�u��Ԃɂ���
	SetActive(true);

	// �q�I�u�W�F�N�g�̏���������
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Init();
	}
}

void GameObject::Update(void) {
	// �A�N�e�B�u����Ȃ�������X�V���������Ȃ�
	if (!isActive_) return;

	// �X�V����
	Update_GameObject();

	// �q�I�u�W�F�N�g�̍X�V����
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Update();
	}
}

void GameObject::Release(void) {
	// �������
	Release_GameObject();

	// �q�I�u�W�F�N�g�̉������
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Release();
	}

	// �폜(���)�������Ƃɂ���
	isDeleted_ = true;
}

bool GameObject::IsActive(void) const {
    return isActive_;
}

void GameObject::SetActive(bool flag) {
	isActive_ = flag;
}

std::weak_ptr<GameObject> GameObject::GetParent(void) const {
	return parent_;
}

const std::vector<std::shared_ptr<GameObject>> GameObject::GetChilds(void) const {
    return childs_;
}

bool GameObject::IsDeleted(void) const {
	return isDeleted_;
}

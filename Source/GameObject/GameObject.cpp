#include "GameObject.h"

GameObject::GameObject(void) : isActive_(true) {

}

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
	if (!IsActive()) return;

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

const std::vector<std::shared_ptr<GameObject>> GameObject::GetChilds(void) const {
    return childs_;
}
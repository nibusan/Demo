#include "GameObject.h"

GameObject::GameObject(void) : 
isActive_(true),
isDeleted_(false) {}

void GameObject::Init(void) {
	//初期化処理
	Init_GameObject();

	// デフォルトでアクティブ状態にする
	SetActive(true);

	// 子オブジェクトの初期化処理
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Init();
	}
}

void GameObject::Update(void) {
	// アクティブじゃなかったら更新処理をしない
	if (!isActive_) return;

	// 更新処理
	Update_GameObject();

	// 子オブジェクトの更新処理
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Update();
	}
}

void GameObject::Release(void) {
	// 解放処理
	Release_GameObject();

	// 子オブジェクトの解放処理
	auto childCount = childs_.size();
	for (size_t i = 0; i < childCount; i++) {
		childs_[i]->Release();
	}

	// 削除(解放)したことにする
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

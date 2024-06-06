#include "../GameObject/2D/UI/UI/AbstractUI.h"
#include "UIInputManager.h"

void UIInputManager::Init(void) {
	selected_ = false;
	clicked_ = false;
}

void UIInputManager::Update(void) {
	if (selectUI_.expired()) return;

	// �O�t���[���őI����Ԃ�����UI���I����Ԃ���Ȃ��Ȃ����烊�Z�b�g����
	if (!selectUI_.lock()->IsSelect()) {
		selected_ = false;
		selectUI_.lock()->SetSelect(false);
		selectUI_.reset();
	}
}

bool UIInputManager::IsSelected(void) const {
	return selected_;
}

void UIInputManager::SetSelected(bool flag) {
	selected_ = flag;
}

bool UIInputManager::IsClicked(void) const {
	return clicked_;
}

void UIInputManager::SetClicked(bool flag) {
	clicked_ = flag;
}

void UIInputManager::SetSelectUI(std::weak_ptr<AbstractUI> ui) {
	if (selectUI_.expired()) {
		selectUI_ = ui;
		selected_ = true;
	}
}

bool UIInputManager::IsSameUI(std::weak_ptr<AbstractUI> ui) {
	return selectUI_.lock() == ui.lock();
}

UIInputManager::UIInputManager(void) :
selected_(false),
clicked_(false) {}
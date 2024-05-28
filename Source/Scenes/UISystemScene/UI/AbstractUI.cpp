#include "AbstractUI.h"

AbstractUI::AbstractUI(void) : isHighlighted_(false) {}

void AbstractUI::Init_GameObject(void) {
	Init_UI();
	SetHighlighted(false);
}

void AbstractUI::Update_GameObject(void) {
	Update_UI();
}

void AbstractUI::Release_GameObject(void) {
	Release_UI();
}

void AbstractUI::SetHighlighted(bool flag) {
	isHighlighted_ = flag;
}

void AbstractUI::HighlightUpdate(void) {}

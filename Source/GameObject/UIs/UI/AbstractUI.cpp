#include "AbstractUI.h"
#include "../../../Common/Handle/Graphic/Graphic.h"

AbstractUI::AbstractUI(void) : 
isHighlighted_(false),
isClickable_(false),
onClickCallBack_(nullptr),
renderCanvas_(std::make_unique<Graphic>(MakeScreen(100, 100, true))) {}

AbstractUI::AbstractUI(const Vector2<float>& canvasSize) : 
isHighlighted_(false),
isClickable_(false),
onClickCallBack_(nullptr),
renderCanvas_(std::make_unique<Graphic>(MakeScreen(static_cast<int>(canvasSize.x), static_cast<int>(canvasSize.y), true))) {}

void AbstractUI::Init_GameObject2D(void) {
	Init_UI();
	SetHighlighted(false);
}

void AbstractUI::Update_GameObject2D(void) {
	Update_UI();
}

void AbstractUI::Release_GameObject2D(void) {
	Release_UI();
}

void AbstractUI::SetHighlighted(bool flag) {
	isHighlighted_ = flag;
}

bool AbstractUI::IsClickable(void) const {
	return isClickable_;
}

void AbstractUI::SetClickable(bool isClickable) {
	isClickable_ = isClickable;
}

void AbstractUI::SetOnClickCallBack(const std::function<void(void)>& callBack) {
	onClickCallBack_ = callBack;
}

void AbstractUI::OnClickDown(void) {}

void AbstractUI::OnClickUp(void) {}

void AbstractUI::HighlightUpdate(void) {}

void AbstractUI::OnClick(void) {
	// コールバック関数がセットされてる時だけ呼び出す
	if (onClickCallBack_ == nullptr) return;
	onClickCallBack_();
}

std::weak_ptr<Graphic> AbstractUI::GetRenderCanvas(void) {
	return renderCanvas_;
}

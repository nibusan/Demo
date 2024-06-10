#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Text/UI_Text.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Managers/InputManager.h"

UI_Button::UI_Button(void) {
	type_ = UI::UI_TYPE::BUTTON;
}

UI_Button::UI_Button(
	const Vector2<float> canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	bool isClickable,
	const std::function<void(void)> onClickCallBack,
	std::weak_ptr<PixelShader> usingPixelShader,
	int usingPixelShaderEventID,
	const std::shared_ptr<UI_Image>& uiImage, 
	const std::shared_ptr<UI_Text>& uiText ) :
AbstractUI(canvasSize, originType, isClickable, onClickCallBack, usingPixelShader, usingPixelShaderEventID),
uiImage_(uiImage),
uiText_(uiText) {
	type_ = UI::UI_TYPE::BUTTON;
}

std::weak_ptr<UI_Image> UI_Button::GetUIImage(void) {
	return uiImage_;
}

std::weak_ptr<UI_Text> UI_Button::GetUIText(void) {
	return uiText_;
}

void UI_Button::Init_UI(void) {
	// このボタンの子として画像をセットする
	AddChild(uiImage_);
	const auto& buttonCanvasSize = renderCanvas_->GetSize().ToVector2f();
	uiImage_->SetTransformData(
		buttonCanvasSize / 2.0f,
		0.0f,
		1.0f
	);
	
	// 画像の子としてテキストをセットする
	uiImage_->AddChild(uiText_);
	uiText_->SetTransformData(
		buttonCanvasSize / 2.0f,
		0.0f,
		1.0f
	);

}

void UI_Button::Update_UI(void) {
	auto& inputManager = InputManager::GetInstance();

}

void UI_Button::Release_UI(void) {
	uiImage_ = nullptr;
	uiText_ = nullptr;
}

void UI_Button::OnClickDown(void) {
	transform_.localScl_ = 1.5f;
}

void UI_Button::OnClickUp(void) {
	transform_.localScl_ = 1.0f;
}

void UI_Button::HighlightUpdate(void) {
	transform_.localScl_ = 0.95f;
}

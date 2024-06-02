#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Text/UI_Text.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_Button::UI_Button(void) {}

UI_Button::UI_Button(
	const Vector2<float> canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	const std::shared_ptr<UI_Image>& uiImage, 
	const std::shared_ptr<UI_Text>& uiText ) :
AbstractUI(canvasSize, originType),
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
	const auto& buttonCanvasSize = renderCanvas_->GetSize().ToVector2f();
	uiImage_->SetTransformData(
		buttonCanvasSize / 2.0f,
		0.0f,
		{ 1.0f, 1.0f }
	);

	// このボタンの子として画像をセットする
	AddChild(uiImage_);
	
	const auto& imageCanvasSize = uiImage_->GetRenderCanvas().lock()->GetSize().ToVector2f();
	uiText_->SetTransformData(
		imageCanvasSize / 2.0f,
		//{ 0.0f, 0.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	// 画像の子としてテキストをセットする
	uiImage_->AddChild(uiText_);
}

void UI_Button::Update_UI(void) {
	//const auto& imageCanvasSize = uiImage_->GetRenderCanvas().lock()->GetSize().ToVector2f();
	//const auto& textCanvasSize = uiText_->GetRenderCanvas().lock()->GetSize().ToVector2f();
	//uiText_->SetTransformData(
	//	imageCanvasSize / 2.0f - textCanvasSize / 2.0f,
	//	//{ 256.0f, 64.0f },
	//	0.0f,
	//	{ 1.0f, 1.0f }
	//);
}

void UI_Button::Release_UI(void) {}

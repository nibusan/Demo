#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Text/UI_Text.h"

UI_Button::UI_Button(const std::shared_ptr<UI_Image>& uiImage, const std::shared_ptr<UI_Text>& uiText) : 
uiImage_(uiImage),
uiText_(uiText) {

}

std::weak_ptr<UI_Image> UI_Button::GetUIImage(void) {
	return uiImage_;
}

std::weak_ptr<UI_Text> UI_Button::GetUIText(void) {
	return uiText_;
}

void UI_Button::Init_UI(void) {
	AddChild(uiImage_);
	// 画像の子としてテキストをセットする
	uiImage_->AddChild(uiText_);
}

void UI_Button::Update_UI(void) {}

void UI_Button::Release_UI(void) {}

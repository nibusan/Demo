#include <DxLib.h>
#include "UI_Text.h"
#include "../../../../../../Common/Handle/Font/Font.h"

UI_Text::UI_Text(void) :
font_(nullptr),
text_(),
textColor_(0x000000) {
	type_ = UI::UI_TYPE::TEXT;
}

UI_Text::UI_Text(
	const Vector2<float>& canvasSize, 
	UI::UI_ORIGIN_TYPE originType, 
	std::shared_ptr<Font> font, 
	const std::string& text, 
	unsigned int color) :
AbstractUI(canvasSize, originType),
font_(font),
text_(text),
textColor_(color) {
	type_ = UI::UI_TYPE::TEXT;
}

std::weak_ptr<Font> UI_Text::GetFont(void) const {
	return font_;
}

std::string UI_Text::GetText(void) const {
	return text_;
}

unsigned int UI_Text::GetTextColor(void) const {
	return textColor_;
}

void UI_Text::Init_UI(void) {

}

void UI_Text::Update_UI(void) {

}

void UI_Text::Release_UI(void) {

}

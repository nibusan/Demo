#include "UI_Text.h"

UI_Text::UI_Text(std::shared_ptr<Font> font, const std::string& text) : 
font_(font),
text_(text) {

}

std::weak_ptr<Font> UI_Text::GetFont(void) const {
	return font_;
}

std::string UI_Text::GetText(void) const {
	return text_;
}

void UI_Text::Init_UI(void) {

}

void UI_Text::Update_UI(void) {

}

void UI_Text::Release_UI(void) {

}

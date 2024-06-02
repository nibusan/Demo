#include "UI_Image.h"

UI_Image::UI_Image(void) {
	type_ = UI::UI_TYPE::BUTTON;
}

UI_Image::UI_Image(
	const Vector2<float>& canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	std::weak_ptr<Graphic> image) : 
AbstractUI(canvasSize, originType), 
image_(image) {
	type_ = UI::UI_TYPE::BUTTON;
}

void UI_Image::Init_UI(void) {

}

void UI_Image::Update_UI(void) {

}

void UI_Image::Release_UI(void) {

}

std::weak_ptr<Graphic> UI_Image::GetImage(void) {
	return image_;
}

void UI_Image::HighlightUpdate(void) {
	
}

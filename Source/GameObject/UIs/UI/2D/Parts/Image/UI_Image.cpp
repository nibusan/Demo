#include "UI_Image.h"

UI_Image::UI_Image(void) : image_(nullptr) {}

UI_Image::UI_Image(const Vector2<float>& canvasSize, std::shared_ptr<Graphic> image) : 
AbstractUI(canvasSize), 
image_(image) {}

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

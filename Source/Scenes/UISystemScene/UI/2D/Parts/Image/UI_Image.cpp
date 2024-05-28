#include "UI_Image.h"

UI_Image::UI_Image(std::shared_ptr<Graphic> image) : image_(image) {}

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

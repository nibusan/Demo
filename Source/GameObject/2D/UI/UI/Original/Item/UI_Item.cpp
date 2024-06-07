#include "UI_Item.h"

UI_Item::UI_Item(
	const Vector2<float> canvasSize,
	UI::UI_ORIGIN_TYPE originType, 
	bool isClickable, 
	const std::function<void(void)> onClickCallBack, 
	std::weak_ptr<PixelShader> usingPixelShader, 
	int usingPixelShaderEventID, 
	std::weak_ptr<Graphic> image,
	std::weak_ptr<Item> item) :
AbstractUI(canvasSize, originType, isClickable, onClickCallBack, usingPixelShader, usingPixelShaderEventID),
image_(image),
item_(item) {}

std::weak_ptr<Item> UI_Item::GetItem(void) {
	return item_;
}

std::weak_ptr<Graphic> UI_Item::GetItemImage(void) {
	return image_;
}

void UI_Item::Init_UI(void) {}

void UI_Item::Update_UI(void) {}

void UI_Item::Release_UI(void) {}

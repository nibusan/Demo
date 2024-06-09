#include <algorithm>
#include "../../../../../../Managers/InputManager.h"
#include "../../AbstractUI.h"
#include "../../Parts/Image/UI_Image.h"
#include "UI_Slider.h"

UI_Slider::UI_Slider(void) {}

UI_Slider::UI_Slider(
	const Vector2<float> canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	bool isClickable, 
	const std::function<void(void)> onClickCallBack, 
	std::weak_ptr<PixelShader> usingPixelShader, 
	int usingPixelShaderEventID, 
	const std::shared_ptr<UI_Image>& uiImage_BaseImage, 
	const std::shared_ptr<UI_Image>& uiImage_CircleImage, 
	const std::shared_ptr<UI_Image>& uiImage_GaugeImage, 
	float min, 
	float max) :
AbstractUI(canvasSize, originType, isClickable, onClickCallBack, usingPixelShader, usingPixelShaderEventID),
uiImage_BaseImage_(uiImage_BaseImage),
uiImage_CircleImage_(uiImage_CircleImage),
uiImage_GaugeImage_(uiImage_GaugeImage),
min_(min),
max_(max),
currentValue_(0.0f) {}

std::weak_ptr<UI_Image> UI_Slider::GetUIImage_BaseImage(void) {
	return uiImage_BaseImage_;
}

std::weak_ptr<UI_Image> UI_Slider::GetUIImage_CircleImage(void) {
	return uiImage_CircleImage_;
}

std::weak_ptr<UI_Image> UI_Slider::GetUIImage_GaugeImage(void) {
	return uiImage_GaugeImage_;
}

float UI_Slider::GetMinValue(void) const {
	return min_;
}

float UI_Slider::GetMaxValue(void) const {
	return max_;
}

float UI_Slider::GetCurrentValue(void) const {
	return currentValue_;
}

void UI_Slider::Init_UI(void) {}

void UI_Slider::Update_UI(void) {}

void UI_Slider::Release_UI(void) {}

void UI_Slider::OnClickDown(void) {
	// クリックしてる間はスライダーの選択する場所の部分(円の部分？)のX座標をマウスと同じ座標にする
	uiImage_CircleImage_->GetTransform().currentPos_.x 
		= std::clamp(InputManager::GetInstance().GetMousePos().ToVector2f().x, min_, max_);
}

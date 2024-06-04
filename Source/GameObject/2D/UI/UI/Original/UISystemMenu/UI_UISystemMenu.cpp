#include "UI_UISystemMenu.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Text/UI_Text.h"
#include "../Button/UI_Button.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_UISystemMenu::UI_UISystemMenu(void) {}

UI_UISystemMenu::UI_UISystemMenu(
	const Vector2<float> canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	bool isClickable,
	const std::function<void(void)> onClickCallBack,
	std::weak_ptr<PixelShader> usingPixelShader,
	int usingPixelShaderEventID, 
	const std::shared_ptr<UI_Image>& backGround, 
	const std::shared_ptr<UI_Text>& title, 
	const std::shared_ptr<UI_Button>& button1, 
	const std::shared_ptr<UI_Button>& button2, 
	const std::shared_ptr<UI_Button>& button3, 
	const std::shared_ptr<UI_Button>& button4) : 
AbstractUI(canvasSize, originType, isClickable, onClickCallBack, usingPixelShader, usingPixelShaderEventID),
uiImage_BackGround_(backGround),
uiText_Title_(title){
	buttonList_[0] = button1;
	buttonList_[1] = button2;
	buttonList_[2] = button3;
	buttonList_[3] = button4;
}

std::weak_ptr<UI_Image> UI_UISystemMenu::GetUIImage(void) {
    return uiImage_BackGround_;
}

std::weak_ptr<UI_Text> UI_UISystemMenu::GetUIText(void) {
	return uiText_Title_;
}

const std::array<std::shared_ptr<UI_Button>, UI_UISystemMenu::BUTTON_COUNT>& UI_UISystemMenu::GetUIButtons(void) {
	return  buttonList_;
}

void UI_UISystemMenu::Init_UI(void) {
	// このボタンの子として画像をセットする
	AddChild(uiImage_BackGround_);
	const auto& menuCanvasSize = renderCanvas_->GetSize().ToVector2f();
	uiImage_BackGround_->SetTransformData(
		menuCanvasSize / 2.0f,
		0.0f,
		1.0f
	);

	uiImage_BackGround_->AddChild(uiText_Title_);
	const auto& imageCanvasSize = uiImage_BackGround_->GetRenderCanvas().lock()->GetSize().ToVector2f();
	uiText_Title_->SetTransformData(
		Vector2<float>(0.0f, 0.0f),
		0.0f,
		1.0f
	);

	// 画像の子としてボタンをセットする
	for (int i = 0; i < BUTTON_COUNT; i++) {
		uiImage_BackGround_->AddChild(buttonList_[i]);
		
		buttonList_[i]->SetTransformData(
			Vector2<float>(menuCanvasSize.x / 2.0f, (imageCanvasSize.y / 5) * (i + 1)),
			0.0f,
			1.0f
		);
	}
}

void UI_UISystemMenu::Update_UI(void) {}

void UI_UISystemMenu::Release_UI(void) {}

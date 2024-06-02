#include <numbers>
#include "UISystemScene.h"
#include "../../GameObject/GameObject2D.h"
#include "../../GameObject/UIs/UI/AbstractUI.h"
#include "../../GameObject/UIs/UI/2D/Parts/Image/UI_Image.h"
#include "../../GameObject/UIs/UI/2D/Parts/Image/UI_ImageRenderer.h"
#include "../../GameObject/UIs/UI/2D/Parts/Text/UI_Text.h"
#include "../../GameObject/UIs/UI/2D/Parts/Text/UI_TextRenderer.h"
#include "../../GameObject/UIs/UI/2D/Original/Button/UI_Button.h"
#include "../../GameObject/UIs/UI/2D/Original/Button/UI_ButtonRenderer.h"
#include "../../Common/Handle/Graphic/Graphic.h"
#include "../../Common/Handle/Font/Font.h"
#include "../../Managers/ResourceManager.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	// リソースファイル取得用
	auto& resourceManager = ResourceManager::GetInstance();

	graphic_ = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_IMAGE_TEST").lock());
	std::weak_ptr<Font> aFont = std::dynamic_pointer_cast<Font>(resourceManager.GetResourceFile("FONT_REVAMPED").lock());
	font_ = std::make_shared<Font>(
		aFont.lock()->GetFontName(),
		32
	);
	Weak_Graphic buttonGraphic = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_BUTTON").lock());
	uiButton_ = std::make_shared<UI_Button>(
		Vector2<float>(800.0f,800.0f),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
				static_cast<float>(GetDrawStringWidthToHandle("Button", 6, font_->GetHandle())),
				static_cast<float>(font_->GetFontSize())
			}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			font_, 
			"Button", 
			0xFFFFFF
		)
	);
	uiButton_->Init();
	uiButton_->SetTransformData(
		{ 0.0f, 0.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	//ui4_ = std::make_shared<UI_Button>(
	//	buttonGraphic->GetSize().ToVector2f(), 
	//	UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
	//	std::make_shared<UI_Image>(buttonGraphic->GetSize().ToVector2f(), 
	//		UI::UI_ORIGIN_TYPE::CENTER_CENTER, buttonGraphic),
	//	std::make_shared<UI_Text>(buttonGraphic->GetSize().ToVector2f(), 
	//		UI::UI_ORIGIN_TYPE::CENTER_CENTER,font_, "Button", 0xFFFFFF)
	//);
	//ui4_->Init();
	//ui4_->SetTransformData(
	//	{ 300.0f, 300.0f },
	//	0.0f,
	//	{ 1.0f, 1.0f }
	//);
	//ui3_->AddChild(ui4_);

	//ui5_ = std::make_shared<UI_Button>(
	//	buttonGraphic->GetSize().ToVector2f(), 
	//	UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
	//	std::make_shared<UI_Image>(buttonGraphic->GetSize().ToVector2f(), 
	//		UI::UI_ORIGIN_TYPE::CENTER_CENTER, buttonGraphic),
	//	std::make_shared<UI_Text>(buttonGraphic->GetSize().ToVector2f(), 
	//		UI::UI_ORIGIN_TYPE::CENTER_CENTER,font_, "Button", 0xFFFFFF)
	//);
	//ui5_->Init();
	//ui5_->SetTransformData(
	//	{ 300.0f, 300.0f },
	//	0.0f,
	//	{ 1.0f, 1.0f }
	//);
	//ui4_->AddChild(ui5_);

	uiButtonRenderer_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(uiButton_));
}

void UISystemScene::Update(void) {
	//ui1_->Update();
	//ui2_->Update();

	uiButton_->Update();
	if(CheckHitKey(KEY_INPUT_W)) uiButton_->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_A)) uiButton_->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_S)) uiButton_->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_D)) uiButton_->GetTransform().localPos_.x++;
	
	auto child = std::dynamic_pointer_cast<GameObject2D>(uiButton_->GetChilds()[0]->GetChilds()[0]);
	if(CheckHitKey(KEY_INPUT_UP)) child->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_LEFT)) child->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_DOWN)) child->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_RIGHT)) child->GetTransform().localPos_.x++;

}

void UISystemScene::Draw(void) {
	uiButtonRenderer_->Render();
}

void UISystemScene::Release(void) {
	uiButton_->Release();
}

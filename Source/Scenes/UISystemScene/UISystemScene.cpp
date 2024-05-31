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

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	graphic_ = std::make_shared<Graphic>("Assets/Scenes/UISystemScene/UI/Button/UI_Image.png");
	font_ = std::make_shared<Font>("Assets/Scenes/UISystemScene/Font/Revamped-X3q1a.ttf", "Revamped", 32);

	ui1_ = std::make_shared<UI_Image>(graphic_->GetSize().ToVector2f(), UI::UI_ORIGIN_TYPE::DOWN_RIGHT, graphic_);
	ui1_->Init();
	ui1_->SetTransformData(
		{ 20.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);
	uiImageRenderer_ = std::make_shared<UI_ImageRenderer>(std::dynamic_pointer_cast<UI_Image>(ui1_));

	ui2_ = std::make_shared<UI_Text>(graphic_->GetSize().ToVector2f(), UI::UI_ORIGIN_TYPE::CENTER_CENTER, font_, "AIUEO", 0x00FF00);
	ui2_->Init();
	ui2_->SetTransformData(
		{ 20.0f, 5.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);
	uiTextRenderer_ = std::make_shared<UI_TextRenderer>(std::dynamic_pointer_cast<UI_Text>(ui2_));
	
	auto buttonGraphic = std::make_shared<Graphic>("Assets/Scenes/UISystemScene/UI/Button/UI_Button.png");
	ui3_ = std::make_shared<UI_Button>(
		buttonGraphic->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
		std::make_shared<UI_Image>(buttonGraphic->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::UP_LEFT, buttonGraphic),
		std::make_shared<UI_Text>(buttonGraphic->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::UP_LEFT,font_, "Button", 0xFFFFFF)
	);
	ui3_->Init();
	ui3_->SetTransformData(
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

	uiButtonRenderer_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(ui3_));
}

void UISystemScene::Update(void) {
	ui1_->Update();
	ui2_->Update();

	ui3_->Update();
	if(CheckHitKey(KEY_INPUT_W)) ui3_->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_A)) ui3_->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_S)) ui3_->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_D)) ui3_->GetTransform().localPos_.x++;
	
	auto child = std::dynamic_pointer_cast<GameObject2D>(ui3_->GetChilds()[0]->GetChilds()[0]);
	if(CheckHitKey(KEY_INPUT_UP)) child->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_LEFT)) child->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_DOWN)) child->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_RIGHT)) child->GetTransform().localPos_.x++;

}

void UISystemScene::Draw(void) {
	uiTextRenderer_->Render();
	uiButtonRenderer_->Render();
	uiImageRenderer_->Render();
}

void UISystemScene::Release(void) {
	ui1_->Release();
	ui2_->Release();
	ui3_->Release();
}

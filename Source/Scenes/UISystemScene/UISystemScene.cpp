#include "UISystemScene.h"
#include "../../GameObject/GameObject2D.h"
#include "../../Scenes/UISystemScene/UI/AbstractUI.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Image/UI_Image.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Image/UI_ImageRenderer.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Text/UI_Text.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Text/UI_TextRenderer.h"
#include "../../Scenes/UISystemScene/UI/2D/Original/Button/UI_Button.h"
#include "../../Scenes/UISystemScene/UI/2D/Original/Button/UI_ButtonRenderer.h"
#include "../../Common/Handle/Graphic/Graphic.h"
#include "../../Common/Handle/Font/Font.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {

	graphic_ = std::make_shared<Graphic>("Assets/Scenes/UISystemScene/UI/Button/UI_Image.png");
	font_ = std::make_shared<Font>("Assets/Scenes/UISystemScene/Font/Revamped-X3q1a.ttf", "Revamped", 32);
	ui1_ = std::make_shared<UI_Image>(graphic_);
	ui1_->Init();
	ui1_->SetTransformData(
		{ 1000.0f, 400.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 1.0f }
	);
	uiImageRenderer_ = std::make_shared<UI_ImageRenderer>(std::dynamic_pointer_cast<UI_Image>(ui1_));

	ui2_ = std::make_shared<UI_Text>(font_, "AIUEO", 0x00FF00);
	ui2_->Init();
	ui2_->SetTransformData(
		{ 20.0f, 5.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 1.0f }
	);
	uiTextRenderer_ = std::make_shared<UI_TextRenderer>(std::dynamic_pointer_cast<UI_Text>(ui2_));
	
	ui3_ = std::make_shared<UI_Button>(
		std::make_shared<UI_Image>(std::make_shared<Graphic>("Assets/Scenes/UISystemScene/UI/Button/UI_Button.png")),
		std::make_shared<UI_Text>(font_, "Button", 0xFFFFFF)
	);
	ui3_->Init();
	ui3_->SetTransformData(
		{ 400.0f, 400.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 1.0f }
	);
	uiButtonRenderer_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(ui3_));
}

void UISystemScene::Update(void) {
	ui1_->Update();
	ui2_->Update();

	if(CheckHitKey(KEY_INPUT_W)) ui3_->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_A)) ui3_->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_S)) ui3_->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_D)) ui3_->GetTransform().localPos_.x++;
	
	auto child = std::dynamic_pointer_cast<GameObject2D>(ui3_->GetChilds()[0]->GetChilds()[0]);
	if(CheckHitKey(KEY_INPUT_UP)) child->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_LEFT)) child->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_DOWN)) child->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_RIGHT)) child->GetTransform().localPos_.x++;

	ui3_->Update();
}

void UISystemScene::Draw(void) {
	uiImageRenderer_->Render();
	uiTextRenderer_->Render();
	uiButtonRenderer_->Render();
}

void UISystemScene::Release(void) {
	ui1_->Release();
	ui2_->Release();
	ui3_->Release();
}

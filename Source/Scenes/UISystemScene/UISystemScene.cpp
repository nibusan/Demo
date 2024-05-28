#include "UISystemScene.h"
#include "../../GameObject/GameObject2D.h"
#include "../../Scenes/UISystemScene/UI/AbstractUI.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Image/UI_Image.h"
#include "../../Scenes/UISystemScene/UI/2D/Parts/Text/UI_Text.h"
#include "../../Scenes/UISystemScene/UI/2D/Original/Button/UI_Button.h"
#include "../../Scenes/UISystemScene/UI/2D/Original/Button/UI_ButtonRenderer.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	ui1_ = std::make_shared<UI_Image>();
	ui1_->Init();
	ui2_ = std::make_shared<UI_Text>();
	ui2_->Init();
	ui3_ = std::make_shared<UI_Button>();
	ui3_->Init();
	uiRenderer_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(ui3_));
}

void UISystemScene::Update(void) {
	ui1_->Update();
	ui2_->Update();
	ui3_->Update();
}

void UISystemScene::Draw(void) {
	uiRenderer_->Render();
}

void UISystemScene::Release(void) {
	ui1_->Release();
	ui2_->Release();
	ui3_->Release();
}

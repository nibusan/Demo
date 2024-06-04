#include <numbers>
#include "UISystemScene.h"
#include "../../GameObject/2D/GameObject2D.h"
#include "../../GameObject/2D/UI/UILayer/UILayerInfo.h"
#include "../../GameObject/2D/UI/UILayer/UILayer.h"
#include "../../Managers/RenderManager.h"
#include "../../Managers/InputManager.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	uiLayer_ = std::make_unique<UILayer>();
	uiLayer_->LoadUILayer(UILayerInfo::TYPE::UI_SYSTEM_MENU);
	uiLayer_->Init();
}

void UISystemScene::Update(void) {
	uiLayer_->Update();
}

void UISystemScene::Release(void) {
	uiLayer_->Release();
}

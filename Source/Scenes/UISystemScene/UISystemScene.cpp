#include <numbers>
#include "UISystemScene.h"
#include "../../GameObject/2D/GameObject2D.h"
#include "../../GameObject/2D/UI/UILayer/UILayerInfo.h"
#include "../../GameObject/2D/UI/UILayer/UILayer.h"
#include "../../GameObject/3D/GameObject3D.h"
#include "../../GameObject/3D/Camera/Camera.h"
#include "../../Managers/RenderManager.h"
#include "../../Managers/InputManager.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	camera_ = std::make_shared<Camera>();
	camera_->Init();
	camera_->SetTransformData(
		{ 0.0f, 0.0f, -10.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f }
	);
	RenderManager::GetInstance().SetMainCamera(camera_);

	uiLayer_ = std::make_unique<UILayer>();
	uiLayer_->LoadUILayer(UILayerInfo::TYPE::UI_SYSTEM_MENU);
	uiLayer_->Init();
}

void UISystemScene::Update(void) {
	camera_->Update();
	uiLayer_->Update();
}

void UISystemScene::Release(void) {
	camera_->Release();
	uiLayer_->Release();
}

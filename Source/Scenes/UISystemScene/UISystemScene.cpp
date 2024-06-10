#include <numbers>
#include "../../GameObject/2D/GameObject2D.h"
#include "../../GameObject/2D/UI/UILayer/UILayerInfo.h"
#include "../../GameObject/2D/UI/UILayer/UILayer.h"
#include "../../GameObject/3D/GameObject3D.h"
#include "../../GameObject/3D/Camera/Camera.h"
#include "../../Managers/RenderManager.h"
#include "../../Managers/InputManager.h"
#include "../../Managers/SceneManager.h"
#include "../../DebugTools/DebugLog.h"
#include "UISystemScene.h"

UISystemScene::UISystemScene(void) {
	// ���̃V�[���̎�ނ��Z�b�g
	type_ = Scene::TYPE::UI_SYSTEM;

	DebugLog::GetInstance().AddLog({1.0f,"UISystemScene", 0x00FFFF});
}

void UISystemScene::Init(void) {
	// ���C���J�����̐ݒ�
	camera_ = std::make_shared<Camera>();
	camera_->Init();
	camera_->SetTransformData(
		{ 0.0f, 0.0f, -10.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f }
	);

	// ���C���J�������Z�b�g
	RenderManager::GetInstance().SetMainCamera(camera_);

	// UILayer�̓ǂݍ��� & ������
	uiLayer_ = std::make_unique<UILayer>();
	uiLayer_->LoadUILayer(UILayerInfo::TYPE::UI_SYSTEM_MENU);
	uiLayer_->Init();
}

void UISystemScene::Update(void) {
	if (InputManager::GetInstance().IsTrgDown(KEY_INPUT_SPACE)) {
		SceneManager::GetInstance().SetNextScene(Scene::TYPE::INVENTORY_SYSTEM);
	}

	camera_->Update();
	uiLayer_->Update();
}

void UISystemScene::Release(void) {
	camera_->Release();
	uiLayer_->Release();
}

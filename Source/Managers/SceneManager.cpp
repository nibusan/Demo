#include <memory>
#include <DxLib.h>
#include "SceneManager.h"
#include "../Scenes/AbstractScene.h"
#include "../Scenes/InventorySystemScene/InventorySystemScene.h"

void SceneManager::ChangeScene(SCENE_TYPE type) {
	if (currentScene_ != nullptr) {
		// ���ɃV�[�����Z�b�g����Ă���ꍇ�͂��̃V�[�����������
		currentScene_->Release();
		currentScene_ = nullptr;
	}

	// �V�[���̐���
	switch (type) {
	case SCENE_TYPE::INVENTORY_SYSTEM: {
		currentScene_ = std::make_unique<InventorySystemScene>();
	}
		break;

	case SCENE_TYPE::NONE:
	default:
		break;
	}
	currentScene_->Init();
}

void SceneManager::Init(void) {
	// �ŏ��̃V�[����ݒ�
	currentScene_ = std::make_unique<InventorySystemScene>();
	currentScene_->Init();
}

void SceneManager::Update(void) {
	// �V�[���̍X�V
	currentScene_->Update();
}

void SceneManager::Draw(void) {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	// �V�[���̕`��
	currentScene_->Draw();

	ScreenFlip();
}

void SceneManager::Release(void) {
	// �V�[���̉��
	currentScene_->Release();
}

#include <memory>
#include <DxLib.h>
#include "SceneManager.h"
#include "../Scenes/AbstractScene.h"
#include "../Scenes/InventorySystemScene/InventorySystemScene.h"
#include "../Scenes/UISystemScene/UISystemScene.h"
#include "ResourceManager.h"

void SceneManager::ChangeScene(Scene::TYPE type) {
	if (currentScene_ != nullptr) {
		// ���ɃV�[�����Z�b�g����Ă���ꍇ�͂��̃V�[�����������
		currentScene_->Release();
		currentScene_ = nullptr;
	}

	// �V�[���̐���
	switch (type) {
	case Scene::TYPE::INVENTORY_SYSTEM: {
		currentScene_ = std::make_unique<InventorySystemScene>();
		break;
	}
	
	case Scene::TYPE::UI_SYSTEM: {
		currentScene_ = std::make_unique<UISystemScene>();
		break;
	}

	case Scene::TYPE::NONE:
	default:
		break;
	}

	// ���̃V�[���Ŏg�����\�[�X�t�@�C����ǂݍ���
	ResourceManager::GetInstance().LoadSceneResourceFile(type);

	// �V�[���̏�����
	currentScene_->Init();
}

Scene::TYPE SceneManager::GetCurrentSceneType(void) {
	return currentScene_->GetType();
}

void SceneManager::Init(void) {
	// �ŏ��̃V�[����ݒ�
	ChangeScene(Scene::TYPE::INVENTORY_SYSTEM);
}

void SceneManager::Update(void) {
	// �V�[���̍X�V
	currentScene_->Update();
}

void SceneManager::Release(void) {
	// �V�[���̉��
	currentScene_->Release();
}

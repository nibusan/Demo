#include <memory>
#include <DxLib.h>
#include "SceneManager.h"
#include "../Scenes/AbstractScene.h"
#include "../Scenes/InventorySystemScene/InventorySystemScene.h"
#include "../Scenes/UISystemScene/UISystemScene.h"
#include "ResourceManager.h"
#include "PixelShaderEventManager.h"

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
	PixelShaderEventManager::GetInstance().Init();

	// �w�i�F�ݒ�
	SetBackgroundColor(40, 0, 0);

	// Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(true);

	// Z�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(true);

	// �o�b�N�J�����O��L���ɂ���
	SetUseBackCulling(true);

	SetCameraNearFar(0.0001f, 5000.0f);

	// ���C�g�̐ݒ�
	SetUseLighting(true);

	// �ŏ��̃V�[����ݒ�
	ChangeScene(Scene::TYPE::UI_SYSTEM);
}

void SceneManager::Update(void) {
	// �V�[���̍X�V
	currentScene_->Update();

	// �s�N�Z���V�F�[�_�Ŏg���萔�o�b�t�@�̍X�V����
	PixelShaderEventManager::GetInstance().Update();
}

void SceneManager::Release(void) {
	// �V�[���̉��
	currentScene_->Release();
}

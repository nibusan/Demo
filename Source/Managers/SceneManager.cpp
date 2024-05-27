#include <memory>
#include <DxLib.h>
#include "SceneManager.h"
#include "../Scenes/AbstractScene.h"
#include "../Scenes/InventorySystemScene/InventorySystemScene.h"
#include "../Scenes/UISystemScene/UISystemScene.h"

void SceneManager::ChangeScene(Scene::TYPE type) {
	if (currentScene_ != nullptr) {
		// 既にシーンがセットされている場合はそのシーンを解放する
		currentScene_->Release();
		currentScene_ = nullptr;
	}

	// シーンの生成
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
	currentScene_->Init();
}

void SceneManager::Init(void) {
	// 最初のシーンを設定
	currentScene_ = std::make_unique<InventorySystemScene>();
	currentScene_->Init();
}

void SceneManager::Update(void) {
	// シーンの更新
	currentScene_->Update();
}

void SceneManager::Draw(void) {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	// シーンの描画
	currentScene_->Draw();

	ScreenFlip();
}

void SceneManager::Release(void) {
	// シーンの解放
	currentScene_->Release();
}

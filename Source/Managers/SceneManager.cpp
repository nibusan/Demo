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

	// 次のシーンで使うリソースファイルを読み込む
	ResourceManager::GetInstance().LoadSceneResourceFile(type);

	// シーンの初期化
	currentScene_->Init();
}

Scene::TYPE SceneManager::GetCurrentSceneType(void) {
	return currentScene_->GetType();
}

void SceneManager::Init(void) {
	PixelShaderEventManager::GetInstance().Init();

	// 最初のシーンを設定
	ChangeScene(Scene::TYPE::UI_SYSTEM);
}

void SceneManager::Update(void) {
	// シーンの更新
	currentScene_->Update();

	// ピクセルシェーダで使う定数バッファの更新処理
	PixelShaderEventManager::GetInstance().Update();
}

void SceneManager::Release(void) {
	// シーンの解放
	currentScene_->Release();
}

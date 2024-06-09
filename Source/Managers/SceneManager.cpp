#include <memory>
#include <DxLib.h>
#include "../Scenes/AbstractScene.h"
#include "../Scenes/InventorySystemScene/InventorySystemScene.h"
#include "../Scenes/UISystemScene/UISystemScene.h"
#include "ResourceManager.h"
#include "RenderManager.h"
#include "PixelShaderEventManager.h"
#include "InputManager.h"
#include "UIInputManager.h"
#include "../Data/MessageList/MessageList.h"
#include "../Library/imgui/imgui.h"
#include "../Library/imgui/backends/imgui_impl_dx11.h"
#include "../Library/imgui/backends/imgui_impl_win32.h"
#include "../Library/imgui/misc/cpp/imgui_stdlib.h"
#include "SceneManager.h"

Scene::TYPE SceneManager::GetCurrentSceneType(void) {
	return currentScene_->GetType();
}

void SceneManager::SetNextScene(Scene::TYPE type) {
	nextSceneType_ = type;
}

void SceneManager::Init(void) {
	// ゲーム内で使用するメッセージを全て読み込む
	MessageList::GetInstance().Init();

	// 定数バッファに関する処理の初期化
	PixelShaderEventManager::GetInstance().Init();

	// 3D関係の初期化
	Init3D();

	// 最初のシーンを設定
	ChangeScene(Scene::TYPE::UI_SYSTEM);

	// 次のシーンの設定
	nextSceneType_ = Scene::TYPE::NONE;

	// ImGuiの初期化
	ImGui::DebugCheckVersionAndDataLayout("1.89.8 WIP", sizeof(ImGuiIO), sizeof(ImGuiStyle), sizeof(ImVec2), sizeof(ImVec4), sizeof(ImDrawVert), sizeof(ImDrawIdx));
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplWin32_Init(DxLib::GetMainWindowHandle());
	ImGui_ImplDX11_Init((ID3D11Device*)GetUseDirect3D11Device(), (ID3D11DeviceContext*)GetUseDirect3D11DeviceContext());
}

void SceneManager::Update(void) {
	// 次のシーンがセットされていたら切り替える
	if (nextSceneType_ != Scene::TYPE::NONE) {
		ChangeScene(nextSceneType_);
		nextSceneType_ = Scene::TYPE::NONE;
	}

	// ImGuiの処理
	ImGuiIO& io = ImGui::GetIO();
	auto mousePos = InputManager::GetInstance().GetMousePos();
	io.AddMousePosEvent(mousePos.x, mousePos.y);
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// シーンの更新
	currentScene_->Update();

	// ピクセルシェーダで使う定数バッファの更新処理
	PixelShaderEventManager::GetInstance().Update();
}

void SceneManager::Release(void) {
	// シーンの解放
	currentScene_->Release();

	// ImGuiの解放
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

SceneManager::SceneManager() : nextSceneType_(Scene::TYPE::NONE) {}

void SceneManager::ChangeScene(Scene::TYPE type) {
	// 登録されてるレンダラーを全て削除する
	RenderManager::GetInstance().Init();

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

	// UIが参照する入力情報の初期化
	UIInputManager::GetInstance().Init();

	// シーンの初期化
	currentScene_->Init();
}

void SceneManager::Init3D(void) {
	// 背景色設定
	SetBackgroundColor(40, 0, 0);

	// Zバッファを有効にする
	SetUseZBuffer3D(true);

	// Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(true);

	// バックカリングを有効にする
	SetUseBackCulling(true);

	SetCameraNearFar(0.0001f, 5000.0f);

	// ライトの設定
	SetUseLighting(true);
}

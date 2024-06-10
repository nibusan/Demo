#include <DxLib.h>
#include "Application.h"
#include "Managers/SceneManager.h"
#include "Managers/InputManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/RenderManager.h"
#include "Managers/UIInputManager.h"
#include "DebugTools/DebugLog.h"

bool Application::Init(void) {
	// ウィンドウを初期化
	Window_Init("Demo", WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, 32);

	// XAudioを使用できるようにする
	SetEnableXAudioFlag(true);

	// Log.txtを出さないようにする
	SetOutApplicationLogValidFlag(false);

	// シェーダーを使えるようにする
	SetUseDirect3DVersion(DX_DIRECT3D_11);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1) {
		return false;
	}

	// 各シングルトンクラスの初期化
	RenderManager::GetInstance().Init();
	InputManager::GetInstance().Init();
	ResourceManager::GetInstance().Init();
	UIInputManager::GetInstance().Init();
	SceneManager::GetInstance().Init();
	DebugLog::GetInstance().Init();

	return true;
}

void Application::Run(void) {
	//ゲームループ開始
	while (ProcessMessage() == 0 && !isShutdown_) {
		if (CheckHitKey(KEY_INPUT_ESCAPE))return;

		//各クラスの情報を更新
		InputManager::GetInstance().Update();
		SceneManager::GetInstance().Update();
		UIInputManager::GetInstance().Update();
		DebugLog::GetInstance().Update();
		
		// 描画するスクリーンの設定 & そのスクリーンをクリア
		SetDrawScreen(DX_SCREEN_BACK);	
		ClearDrawScreen();
		
		// 描画
		RenderManager::GetInstance().Render();

		// 裏の画面を表の画面にコピー
		ScreenFlip();
	}
}

void Application::Release(void) {
	SceneManager::GetInstance().Release();
	ResourceManager::GetInstance().Release();
	DxLib_End();
}

void Application::Shutdown(void) {
	isShutdown_ = true;
}

void Application::Window_Init(std::string name, int screenWidth, int screenHeight, int bitColor) {
	// ウィンドウのタイトルを設定
	SetWindowText(name.c_str());

	// ウィンドウのサイズと色モードを設定
	SetGraphMode(screenWidth, screenHeight, bitColor);
	
	// 仮想フルスクリーンにするための処理
	ChangeWindowMode(true);
	//GetDefaultState(&screenWidth, &screenHeight, &bitColor);
	SetWindowSize(screenWidth, screenHeight);
}

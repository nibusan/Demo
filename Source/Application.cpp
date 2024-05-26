#include <DxLib.h>
#include "Application.h"
#include "Managers/SceneManager.h"

bool Application::Init(void) {
	// ウィンドウを初期化
	Window_Init("Unkn0wn Level", WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, 32);

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

	SceneManager::GetInstance().Init();
	
	return true;
}

void Application::Run(void) {
	//ゲームループ開始
	while (ProcessMessage() == 0 && !isShutdown_) {
		
		//各クラスの情報を更新
		SceneManager::GetInstance().Update();
		
		// 描画するスクリーンの設定 & そのスクリーンをクリア
		SetDrawScreen(DX_SCREEN_BACK);	
		ClearDrawScreen();
		
		// シーンの描画
		SceneManager::GetInstance().Draw();

		// 裏の画面を表の画面にコピー
		ScreenFlip();
	}
}

void Application::Release(void) {
	SceneManager::GetInstance().Release();
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
	GetDefaultState(&screenWidth, &screenHeight, &bitColor);
	SetWindowSize(screenWidth, screenHeight);
}

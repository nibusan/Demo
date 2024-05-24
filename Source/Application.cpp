#include <DxLib.h>
#include "Application.h"

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
}

void Application::Run(void) {
	//ゲームループ開始
	while (ProcessMessage() == 0 && !isShutdown_) {
		

		//各クラスの情報を更新
		

		//描画処理
		//SceneManager::GetInstance().Draw();

		SetDrawScreen(DX_SCREEN_BACK);	// 描画する画面を裏の画面に設定
		ClearDrawScreen();				// 描画する画面の内容を消去
		

		ScreenFlip(); // 裏の画面を表の画面に瞬間コピー

	}
}

void Application::Release(void) {
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

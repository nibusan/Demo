// プロジェクト：技術デモ(WHITE WATER ver)

#include <DxLib.h>
#include <crtdbg.h>
#include "Application.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	//アプリケーションを起動する
	auto& app = Application::GetInstance();

	if (!app.Init()) {
		//初期化に失敗した場合はそこで終了させる
		return -1;
	}

	// アプリケーションを実行する
	app.Run();

	// 後始末
	app.Release();

	return 0;
}
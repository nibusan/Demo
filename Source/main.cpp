// プロジェクト：技術デモ(WHITE WATER ver)

#include <DxLib.h>
#include <crtdbg.h>
#include "Library/imgui/imgui.h"
#include "Library/imgui/backends/imgui_impl_dx11.h"
#include "Library/imgui/backends/imgui_impl_win32.h"
#include "Application.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// メモリリークを検知できるようにする
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetHookWinProc(WndProc);

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
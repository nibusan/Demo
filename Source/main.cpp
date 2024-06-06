// �v���W�F�N�g�F�Z�p�f��(WHITE WATER ver)

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
	// ���������[�N�����m�ł���悤�ɂ���
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetHookWinProc(WndProc);

	//�A�v���P�[�V�������N������
	auto& app = Application::GetInstance();

	if (!app.Init()) {
		//�������Ɏ��s�����ꍇ�͂����ŏI��������
		return -1;
	}

	// �A�v���P�[�V���������s����
	app.Run();

	// ��n��
	app.Release();

	return 0;
}
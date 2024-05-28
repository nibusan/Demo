// �v���W�F�N�g�F�Z�p�f��(WHITE WATER ver)

#include <DxLib.h>
#include <crtdbg.h>
#include "Application.h"

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	// ���������[�N�����m�ł���悤�ɂ���
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
#include <DxLib.h>
#include "Application.h"
#include "Managers/SceneManager.h"
#include "Managers/InputManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/RenderManager.h"
#include "Managers/UIInputManager.h"
#include "DebugTools/DebugLog.h"

bool Application::Init(void) {
	// �E�B���h�E��������
	Window_Init("Demo", WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, 32);

	// XAudio���g�p�ł���悤�ɂ���
	SetEnableXAudioFlag(true);

	// Log.txt���o���Ȃ��悤�ɂ���
	SetOutApplicationLogValidFlag(false);

	// �V�F�[�_�[���g����悤�ɂ���
	SetUseDirect3DVersion(DX_DIRECT3D_11);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1) {
		return false;
	}

	// �e�V���O���g���N���X�̏�����
	RenderManager::GetInstance().Init();
	InputManager::GetInstance().Init();
	ResourceManager::GetInstance().Init();
	UIInputManager::GetInstance().Init();
	SceneManager::GetInstance().Init();
	DebugLog::GetInstance().Init();

	return true;
}

void Application::Run(void) {
	//�Q�[�����[�v�J�n
	while (ProcessMessage() == 0 && !isShutdown_) {
		if (CheckHitKey(KEY_INPUT_ESCAPE))return;

		//�e�N���X�̏����X�V
		InputManager::GetInstance().Update();
		SceneManager::GetInstance().Update();
		UIInputManager::GetInstance().Update();
		DebugLog::GetInstance().Update();
		
		// �`�悷��X�N���[���̐ݒ� & ���̃X�N���[�����N���A
		SetDrawScreen(DX_SCREEN_BACK);	
		ClearDrawScreen();
		
		// �`��
		RenderManager::GetInstance().Render();

		// ���̉�ʂ�\�̉�ʂɃR�s�[
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
	// �E�B���h�E�̃^�C�g����ݒ�
	SetWindowText(name.c_str());

	// �E�B���h�E�̃T�C�Y�ƐF���[�h��ݒ�
	SetGraphMode(screenWidth, screenHeight, bitColor);
	
	// ���z�t���X�N���[���ɂ��邽�߂̏���
	ChangeWindowMode(true);
	//GetDefaultState(&screenWidth, &screenHeight, &bitColor);
	SetWindowSize(screenWidth, screenHeight);
}

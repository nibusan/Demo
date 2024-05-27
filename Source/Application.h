#pragma once
#include <string>
#include "Common/StaticSingleton.h"

class Application : public StaticSingleton<Application> {
public:
	// �E�B���h�E�̃T�C�Y
	static constexpr int WINDOW_SIZE_WIDTH = 1920;
	static constexpr int WINDOW_SIZE_HEIGHT = 1080;

	// 1�b������̃t���[����
	static constexpr int FRAME_TIME = 60;
	
	// 1�b������̃t���[����
	static constexpr float DELTA_TIME = 1.0f / static_cast<float>(FRAME_TIME);

	~Application(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(Application);

	/// @brief ����������
	/// @return ������������������
	bool Init(void);

	/// @brief �A�v���P�[�V�����̎��s 
	void Run(void);

	/// @brief �������
	void Release(void);

	/// @brief �V���b�g�_�E������ 
	void Shutdown(void);
private:
	bool isShutdown_;

	Application(void) = default;

	/// @brief �E�B���h�E�Ɋւ��鏉��������
	/// @param name �E�B���h�E�̃^�C�g��
	/// @param screenWidth �E�B���h�E�̉���
	/// @param screenHeight �E�B���h�E�̏c��
	/// @param bitColor �F���[�h
	void Window_Init(std::string name, int screenWidth, int screenHeight, int bitColor);
};
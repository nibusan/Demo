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
	// �Q�[�����Ŏg�p���郁�b�Z�[�W��S�ēǂݍ���
	MessageList::GetInstance().Init();

	// �萔�o�b�t�@�Ɋւ��鏈���̏�����
	PixelShaderEventManager::GetInstance().Init();

	// 3D�֌W�̏�����
	Init3D();

	// �ŏ��̃V�[����ݒ�
	ChangeScene(Scene::TYPE::UI_SYSTEM);

	// ���̃V�[���̐ݒ�
	nextSceneType_ = Scene::TYPE::NONE;

	// ImGui�̏�����
	ImGui::DebugCheckVersionAndDataLayout("1.89.8 WIP", sizeof(ImGuiIO), sizeof(ImGuiStyle), sizeof(ImVec2), sizeof(ImVec4), sizeof(ImDrawVert), sizeof(ImDrawIdx));
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplWin32_Init(DxLib::GetMainWindowHandle());
	ImGui_ImplDX11_Init((ID3D11Device*)GetUseDirect3D11Device(), (ID3D11DeviceContext*)GetUseDirect3D11DeviceContext());
}

void SceneManager::Update(void) {
	// ���̃V�[�����Z�b�g����Ă�����؂�ւ���
	if (nextSceneType_ != Scene::TYPE::NONE) {
		ChangeScene(nextSceneType_);
		nextSceneType_ = Scene::TYPE::NONE;
	}

	// ImGui�̏���
	ImGuiIO& io = ImGui::GetIO();
	auto mousePos = InputManager::GetInstance().GetMousePos();
	io.AddMousePosEvent(mousePos.x, mousePos.y);
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// �V�[���̍X�V
	currentScene_->Update();

	// �s�N�Z���V�F�[�_�Ŏg���萔�o�b�t�@�̍X�V����
	PixelShaderEventManager::GetInstance().Update();
}

void SceneManager::Release(void) {
	// �V�[���̉��
	currentScene_->Release();

	// ImGui�̉��
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

SceneManager::SceneManager() : nextSceneType_(Scene::TYPE::NONE) {}

void SceneManager::ChangeScene(Scene::TYPE type) {
	// �o�^����Ă郌���_���[��S�č폜����
	RenderManager::GetInstance().Init();

	if (currentScene_ != nullptr) {
		// ���ɃV�[�����Z�b�g����Ă���ꍇ�͂��̃V�[�����������
		currentScene_->Release();
		currentScene_ = nullptr;
	}

	// �V�[���̐���
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

	// ���̃V�[���Ŏg�����\�[�X�t�@�C����ǂݍ���
	ResourceManager::GetInstance().LoadSceneResourceFile(type);

	// UI���Q�Ƃ�����͏��̏�����
	UIInputManager::GetInstance().Init();

	// �V�[���̏�����
	currentScene_->Init();
}

void SceneManager::Init3D(void) {
	// �w�i�F�ݒ�
	SetBackgroundColor(40, 0, 0);

	// Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(true);

	// Z�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(true);

	// �o�b�N�J�����O��L���ɂ���
	SetUseBackCulling(true);

	SetCameraNearFar(0.0001f, 5000.0f);

	// ���C�g�̐ݒ�
	SetUseLighting(true);
}

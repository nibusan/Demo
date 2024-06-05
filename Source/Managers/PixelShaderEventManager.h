#pragma once
#include <utility>
#include <unordered_map>
#include <functional>
#include "../Common/StaticSingleton.h"

class PixelShader;
/// @brief �s�N�Z���V�F�[�_�[���g���ۂɎg�p����萔�o�b�t�@���Ǘ�����C�x���g���Ǘ�����N���X
class PixelShaderEventManager : public StaticSingleton<PixelShaderEventManager> {
public:

	~PixelShaderEventManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(PixelShaderEventManager);

	void Init(void);
	void Update(void);

	/// @brief �w�肳�ꂽ�C�x���g���g�p�ł���悤�ɓn���ꂽ�s�N�Z���V�F�[�_�[�̒萔�o�b�t�@������������
	/// @param eventID �C�x���gID
	/// @param pixelShader �s�N�Z���V�F�[�_�[
	void InitPixelShader(int eventID, std::weak_ptr<PixelShader> pixelShader);

	/// @brief �w�肳�ꂽ�萔�o�b�t�@������������
	/// @param eventID �C�x���gID
	void InitEvent(int eventID);

	/// @brief �w�肳�ꂽ�萔�o�b�t�@�̍X�V�������n�߂�
	/// @param eventID �C�x���gID
	void StartUpdateEvent(int eventID);

	/// @brief �w�肳�ꂽ�萔�o�b�t�@�̍X�V�������~�߂�
	/// @param eventID �C�x���gID
	void StopUpdateEvent(int eventID);

	/// @brief �萔�o�b�t�@��o�^
	/// @param eventId �C�x���gID 
	/// @param constantBuffer �萔�o�b�t�@
	void RegisterConstantBuffer(int eventID, int constantBuffer);
private:
	/// @brief �C�x���g�̍\����
	/// @param initFunction �������������s���֐��I�u�W�F�N�g
	/// @param updateFunction �X�V�������s���֐��I�u�W�F�N�g
	/// @param isActive �X�V�������s����
	/// @param size ���̃C�x���g�����s����̂ɕK�v�Ȓ萔�o�b�t�@�̃T�C�Y
	struct EVENT_DATA {
		EVENT_DATA(void) : initFunction(nullptr), updateFunction(nullptr), isActive(false), size(0) {};
		~EVENT_DATA(void) = default;
		std::function<void(void)> initFunction;
		std::function<void(void)> updateFunction;
		bool isActive;
		size_t size;
	};

	// �e�萔�o�b�t�@�̃C�x���g���Ǘ�
	std::unordered_map<int,EVENT_DATA> eventList_;

	// �萔�o�b�t�@���Ǘ�(�L�[:�C�x���gID, �l:�萔�o�b�t�@)
	std::unordered_map<int, int> constantBufferList_;

	PixelShaderEventManager(void) = default;
	
	/// @brief �e�萔�o�b�t�@�̃C�x���g��o�^����
	void RegisterEvent(void);
};
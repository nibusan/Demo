#include <DxLib.h>
#include "../Common/Handle/PixelShader/PixelShader.h"
#include "PixelShaderEventManager.h"

void PixelShaderEventManager::Init(void) {
	// �e�C�x���g�̓o�^
	RegisterEvent();
}

void PixelShaderEventManager::Update(void) {
	for (const auto& itr : eventList_) {
		// isActive��true��������X�V�������s��
		if (itr.second.isActive) {
			itr.second.updateFunction();
		}
	}
}

void PixelShaderEventManager::InitPixelShader(int eventID, std::weak_ptr<PixelShader> pixelShader) {
	// �w�肳�ꂽ�C�x���g���K�v�Ƃ���T�C�Y�̒萔�o�b�t�@�𐶐�����
	pixelShader.lock()->CreateConstantBuffer(eventList_[eventID].size);
	RegisterConstantBuffer(eventID, pixelShader.lock()->GetConstantBuffer());
}

void PixelShaderEventManager::InitEvent(int eventID) {
	eventList_[eventID].initFunction();
}

void PixelShaderEventManager::StartUpdateEvent(int eventID) {
	eventList_[eventID].isActive = true;
}

void PixelShaderEventManager::StopUpdateEvent(int eventID) {
	eventList_[eventID].isActive = false;
}

void PixelShaderEventManager::RegisterConstantBuffer(int eventID, int constantBuffer) {
	constantBufferList_[eventID] = constantBuffer;
}

void PixelShaderEventManager::RegisterEvent(void) {
	eventList_[-1].initFunction = [this](void) {
		// �������Ȃ�
	};
	eventList_[-1].updateFunction = [this](void) {
		// �������Ȃ�
	};
	eventList_[-1].isActive = false;
	eventList_[-1].size = 0;

	eventList_[0].initFunction = [this](void) {
		// �萔�o�b�t�@���擾
		auto constantBuffer = constantBufferList_[0];
		float* constantBufferF = static_cast<float*>(GetBufferShaderConstantBuffer(constantBuffer));

		// �l�̃Z�b�g
		constantBufferF[0] = 0.0f;
	};
	eventList_[0].updateFunction = [this](void) {
		// �萔�o�b�t�@���擾
		auto constantBuffer = constantBufferList_[0];
		float* constantBufferF = static_cast<float*>(GetBufferShaderConstantBuffer(constantBuffer));

		// �l�̃Z�b�g
		const float addValue = 0.01f;
		constantBufferF[0] += addValue;
	};
	eventList_[0].isActive = false;
	eventList_[0].size = sizeof(float) * 4;
}
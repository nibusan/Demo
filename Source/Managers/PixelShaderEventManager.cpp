#include <DxLib.h>
#include "../Common/Handle/PixelShader/PixelShader.h"
#include "PixelShaderEventManager.h"

void PixelShaderEventManager::Init(void) {
	// 各イベントの登録
	RegisterEvent();
}

void PixelShaderEventManager::Update(void) {
	for (const auto& itr : eventList_) {
		// isActiveがtrueだったら更新処理を行う
		if (itr.second.isActive) {
			itr.second.updateFunction();
		}
	}
}

void PixelShaderEventManager::InitPixelShader(int eventID, std::weak_ptr<PixelShader> pixelShader) {
	// 指定されたイベントが必要とするサイズの定数バッファを生成する
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
		// 何もしない
	};
	eventList_[-1].updateFunction = [this](void) {
		// 何もしない
	};
	eventList_[-1].isActive = false;
	eventList_[-1].size = 0;

	eventList_[0].initFunction = [this](void) {
		// 定数バッファを取得
		auto constantBuffer = constantBufferList_[0];
		float* constantBufferF = static_cast<float*>(GetBufferShaderConstantBuffer(constantBuffer));

		// 値のセット
		constantBufferF[0] = 0.0f;
	};
	eventList_[0].updateFunction = [this](void) {
		// 定数バッファを取得
		auto constantBuffer = constantBufferList_[0];
		float* constantBufferF = static_cast<float*>(GetBufferShaderConstantBuffer(constantBuffer));

		// 値のセット
		const float addValue = 0.01f;
		constantBufferF[0] += addValue;
	};
	eventList_[0].isActive = false;
	eventList_[0].size = sizeof(float) * 4;
}
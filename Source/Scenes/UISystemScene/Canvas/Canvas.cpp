#include "Canvas.h"
#include "../UILayer/AbstractUILayer.h"

void Canvas::Init(void) {
	for (const auto& uiLayer : uiLayers_) {
		uiLayer->Init();
	}
}

void Canvas::Update(void) {
	for (const auto& uiLayer : uiLayers_) {
		uiLayer->Update();
	}
}

void Canvas::Release(void) {
	for (const auto& uiLayer : uiLayers_) {
		uiLayer->Release();
	}
}

void Canvas::AddLayer(std::shared_ptr<AbstractUILayer> uiLayer) {
	uiLayers_.emplace_back(uiLayer);
}

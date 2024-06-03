#include "RenderManager.h"
#include "../Renderer/AbstractRenderer.h"

void RenderManager::Init(void) {
	renderer2D_.clear();
	renderer3D_.clear();
}

void RenderManager::Render(void) {
	// 3D -> 2D�̏��Ԃŕ`�悷��
	Render3D();
	Render2D();
}

void RenderManager::Release(void) {
	
}

void RenderManager::AddRenderer2D(std::shared_ptr<AbstractRenderer> renderer2D) {
	renderer2D_.emplace_back(renderer2D);
}

void RenderManager::AddRenderer3D(std::shared_ptr<AbstractRenderer> renderer3D) {
	renderer3D_.emplace_back(renderer3D);
}

void RenderManager::Render2D(void) {
	for (const auto& renderer2D : renderer2D_) {
		renderer2D->Begin();
		renderer2D->Render();
		renderer2D->End();
	}
}

void RenderManager::Render3D(void) {
	for (const auto& renderer3D : renderer3D_) {
		renderer3D->Begin();
		renderer3D->Render();
		renderer3D->End();
	}
}

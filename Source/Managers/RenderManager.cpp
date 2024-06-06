#include "../GameObject/3D/Camera/Camera.h"
#include "../Renderer/AbstractRenderer.h"
#include "../Debug/DebugLog.h"
#include "RenderManager.h"

void RenderManager::Init(void) {
	renderer2D_.clear();
	renderer3D_.clear();
}

void RenderManager::Render(void) {
	// 3D -> 2Dの順番で描画する
	Render3D();
	Render2D();

	// デバッグログの描画
	const auto& logs = DebugLog::GetInstance().GetLogs();
	for (int i = 0; i < logs.size(); i++) {
		DrawString(
			0,
			16 * i,
			logs[i].log.c_str(),
			logs[i].logColor
		);
	}
}

void RenderManager::Release(void) {
	
}

void RenderManager::AddRenderer2D(std::shared_ptr<AbstractRenderer> renderer2D) {
	renderer2D_.emplace_back(renderer2D);
}

void RenderManager::AddRenderer3D(std::shared_ptr<AbstractRenderer> renderer3D) {
	renderer3D_.emplace_back(renderer3D);
}

void RenderManager::SetMainCamera(std::shared_ptr<Camera> mainCamera) {
	mainCamera_ = mainCamera;
}

void RenderManager::Render2D(void) {
	for (const auto& renderer2D : renderer2D_) {
		renderer2D->Begin();
		renderer2D->Render();
		renderer2D->End();
	}
}

void RenderManager::Render3D(void) {
	mainCamera_->SetBeforeDraw();
	DrawSphere3D(
		{},
		1.0f,
		16,
		0xFF0000,
		0xFF0000,
		false
	);

	for (const auto& renderer3D : renderer3D_) {
		renderer3D->Begin();
		renderer3D->Render();
		renderer3D->End();
	}
}

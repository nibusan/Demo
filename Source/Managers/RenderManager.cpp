#include <DxLib.h>
#include "../GameObject/3D/Camera/Camera.h"
#include "../Renderer/AbstractRenderer.h"
#include "../DebugTools/DebugLog.h"
#include "../Library/imgui/imgui.h"
#include "../Library/imgui/backends/imgui_impl_dx11.h"
#include "../Library/imgui/backends/imgui_impl_win32.h"
#include "../Library/imgui/misc/cpp/imgui_stdlib.h"
#include "RenderManager.h"

void RenderManager::Init(void) {
	renderer2D_.clear();
	renderer3D_.clear();
}

void RenderManager::Render(void) {
	// 3D -> 2D�̏��Ԃŕ`�悷��
	Render3D();
	Render2D();

	// ImGui�̕`��
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	RefreshDxLibDirect3DSetting();

	// �f�o�b�O���O�̕`��
	const auto& logs = DebugLog::GetInstance().GetLogs();
	for (int i = 0; i < logs.size(); i++) {
		DrawString(
			0,
			DEFAULT_FONT_SIZE * i,
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
		// �`��Ώۂ��폜����ĂȂ�������`�悷��
		if (renderer2D->IsDeleted()) continue;
		renderer2D->Begin();
		renderer2D->Render();
		renderer2D->End();
	}
}

void RenderManager::Render3D(void) {
	// ���C���J�����̐ݒ�
	mainCamera_->SetBeforeDraw();

	for (const auto& renderer3D : renderer3D_) {
		// �`��Ώۂ��폜����ĂȂ�������`�悷��
		if (renderer3D->IsDeleted()) continue;
		renderer3D->Begin();
		renderer3D->Render();
		renderer3D->End();
	}
}

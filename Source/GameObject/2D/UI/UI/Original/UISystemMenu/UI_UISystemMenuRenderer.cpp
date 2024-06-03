#include "UI_UISystemMenuRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

UI_UISystemMenuRenderer::UI_UISystemMenuRenderer(bool useLocalPos, const std::shared_ptr<UI_UISystemMenu>& uiSystemMenu) :
AbstractRenderer(useLocalPos),
uiSystemMenu_(uiSystemMenu) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, uiSystemMenu_->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(true, uiSystemMenu_->GetUIText().lock());
	const auto& buttonList = uiSystemMenu_->GetUIButtons();
	for (int i = 0; i < UI_UISystemMenu::BUTTON_COUNT; i++) {
		buttonRenderers_[i] = std::make_unique<UI_ButtonRenderer>(true, buttonList[i]);
	}
}

void UI_UISystemMenuRenderer::Begin(void) {
	// ���̕`��p�X�N���[����ޔ�����
	defaultScreenHadle_ = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiSystemMenu_->GetRenderCanvas();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void UI_UISystemMenuRenderer::Render(void) {
	// ���ꂼ���UI��`�悷��
	imageRenderer_->Begin();
	imageRenderer_->Render();
	textRenderer_->Begin();
	textRenderer_->Render();
	textRenderer_->End();
	for (const auto& buttonRenderer : buttonRenderers_) {
		buttonRenderer->Begin();
		buttonRenderer->Render();
		buttonRenderer->End();
	}
	imageRenderer_->End();

	// �f�o�b�O�p
	DebugRender();
}

void UI_UISystemMenuRenderer::End(void) {
	// UI�̊�b�f�[�^���擾
	const auto& transform = uiSystemMenu_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiSystemMenu_->GetParent();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiSystemMenu_->GetRenderCanvas();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = uiSystemMenu_->GetCanvasRenderOffset();

	if (parent.lock() != nullptr) {
		if (useLocalPos_) {
			renderCanvas.lock()->Draw(
				transform.localPos_ + offset,
				1.0f,
				transform.currentRot_,
				nullptr
			);
		}
		else {
			renderCanvas.lock()->Draw(
				transform.currentPos_ + offset,
				1.0f,
				transform.currentRot_,
				nullptr
			);
		}
	}
	else {
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			1.0f,
			transform.currentRot_,
			nullptr
		);
	}
}

void UI_UISystemMenuRenderer::DebugRender(void) {

}

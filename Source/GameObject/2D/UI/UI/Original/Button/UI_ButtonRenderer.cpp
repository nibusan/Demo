#include <DxLib.h>
#include "UI_ButtonRenderer.h"
#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_Text.h"
#include "../../Parts/Text/UI_TextRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ButtonRenderer::UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton) : uiButton_(uiButton) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(uiButton_->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(uiButton_->GetUIText().lock());
}

void UI_ButtonRenderer::Begin(void) {
	if (uiButton_ == nullptr) return;
	if (!uiButton_->IsChildUIClipped()) return;

	// ���̕`��p�X�N���[����ޔ�����
	defaultScreenHadle_ = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void UI_ButtonRenderer::Render(void) {
	if (uiButton_ == nullptr) return;
	// ���ꂼ���UI��`�悷��
	imageRenderer_->Begin();
	imageRenderer_->Render();
	textRenderer_->Begin();
	textRenderer_->Render();
	textRenderer_->End();
	imageRenderer_->End();
	
	// �f�o�b�O�p
	DebugRender();
}

void UI_ButtonRenderer::End(void) {
	if (uiButton_ == nullptr) return;
	if (!uiButton_->IsChildUIClipped()) return;

	// UI�̊�b�f�[�^���擾
	const auto& transform = uiButton_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiButton_->GetParent();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = uiButton_->GetCanvasRenderOffset();

	renderCanvas.lock()->Draw(uiButton_->GetUIImage().lock()->IsChildUIClipped() ? transform.currentPos_ + offset : transform.currentPos_ + offset, true, nullptr);
}

void UI_ButtonRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();
	
	// �f�o�b�O�p�̃{�b�N�X
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFFFF00,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFFFF00
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0xFFFF00
	);
}

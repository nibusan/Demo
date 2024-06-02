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

void UI_ButtonRenderer::Render(void) {
	// ���̕`��p�X�N���[����ޔ�����
	const auto preRenderScreen = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	// UI�̊�b�f�[�^���擾
	const auto& transform = uiButton_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiButton_->GetParent();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();

	// ���ꂼ���UI��`�悷��
	imageRenderer_->Render();
	
	// ���̕`��p�X�N���[����ޔ�����
	const auto preRenderScreen2 = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas2 = uiButton_->GetUIImage().lock()->GetRenderCanvas();

	// UI�̊�b�f�[�^���擾
	const auto& transform2 = uiButton_->GetUIImage().lock()->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent2 = uiButton_->GetUIImage().lock()->GetParent();

	SetDrawScreen(renderCanvas2.lock()->GetHandle());
	ClearDrawScreen();
	
	textRenderer_->Render();

	SetDrawScreen(preRenderScreen2);

	auto offset2 = uiButton_->GetUIText().lock()->GetCanvasRenderOffset();

	renderCanvas2.lock()->Draw(parent2.lock() == nullptr ? transform2.currentPos_ + offset2: transform2.localPos_ + offset2, true, nullptr);

	// �f�o�b�O�p
	DebugRender();

	SetDrawScreen(preRenderScreen);

	auto offset = uiButton_->GetCanvasRenderOffset();

	renderCanvas.lock()->Draw(parent.lock() == nullptr ? transform.currentPos_ + offset: transform.localPos_ + offset, true, nullptr);
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

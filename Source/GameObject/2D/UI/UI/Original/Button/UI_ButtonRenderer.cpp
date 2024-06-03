#include <DxLib.h>
#include "UI_ButtonRenderer.h"
#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_Text.h"
#include "../../Parts/Text/UI_TextRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ButtonRenderer::UI_ButtonRenderer(bool useLocalPos, const std::shared_ptr<UI_Button> uiButton) : 
AbstractRenderer(useLocalPos),
uiButton_(uiButton) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, uiButton_->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(true, uiButton_->GetUIText().lock());
}

void UI_ButtonRenderer::Begin(void) {
	// ���̕`��p�X�N���[����ޔ�����
	defaultScreenHadle_ = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void UI_ButtonRenderer::Render(void) {
	// ���ꂼ���UI��`�悷��
	imageRenderer_->Begin();
	imageRenderer_->Render();
	imageRenderer_->End();
	textRenderer_->Begin();
	textRenderer_->Render();
	textRenderer_->End();
	
	// �f�o�b�O�p
	DebugRender();
}

void UI_ButtonRenderer::End(void) {
	// UI�̊�b�f�[�^���擾
	const auto& transform = uiButton_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiButton_->GetParent();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = uiButton_->GetCanvasRenderOffset();

	/*renderCanvas.lock()->Draw(
		(uiButton_->GetParent().lock() == nullptr) && uiButton_->IsChildUIClipped() ? transform.localPos_ + offset : transform.currentPos_ + offset,
		true, 
		nullptr
	);*/

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

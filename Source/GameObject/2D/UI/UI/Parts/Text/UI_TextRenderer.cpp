#include <DxLib.h>
#include "UI_TextRenderer.h"
#include "UI_Text.h"
#include "../../../../../../GameObject/Transform.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Common/Handle/Font/Font.h"

UI_TextRenderer::UI_TextRenderer(bool useLocalPos, std::shared_ptr<UI_Text> uiText) : 
AbstractRenderer(useLocalPos),
uiText_(uiText) {}

void UI_TextRenderer::Begin(void) {
	// ���̕`��p�X�N���[����ޔ�����
	defaultScreenHadle_ = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiText_->GetRenderCanvas();

	// �`��X�N���[����UI�`��p�L�����o�X�ɐ؂�ւ���
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void UI_TextRenderer::Render(void) {
	uiText_->GetFont().lock()->Draw(Vector2<float>(0.0f, 0.0f), uiText_->GetText(), uiText_->GetTextColor());

	// �f�o�b�O�p
	DebugRender();
}

void UI_TextRenderer::End(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiText_->GetRenderCanvas();

	// UI�̊�b�f�[�^���擾
	const auto& transform = uiText_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiText_->GetParent();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = uiText_->GetCanvasRenderOffset();

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

void UI_TextRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiText_->GetRenderCanvas();

	// �f�o�b�O�p�̃{�b�N�X
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FF00,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FF00
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0x00FF00
	);
}

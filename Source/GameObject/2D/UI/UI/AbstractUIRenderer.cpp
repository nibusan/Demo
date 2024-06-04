#include "../../../../Renderer/AbstractRenderer.h"
#include "AbstractUI.h"
#include "AbstractUIRenderer.h"

AbstractUIRenderer::AbstractUIRenderer(bool useLocalPos, std::shared_ptr<AbstractUI> ui) : 
AbstractRenderer(useLocalPos),
ui_(ui) {}

void AbstractUIRenderer::Begin(void) {
	// ���̕`��p�X�N���[����ޔ�����
	defaultScreenHadle_ = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = ui_->GetRenderCanvas();

	// �`��X�N���[����UI�`��p�L�����o�X�ɐ؂�ւ���
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void AbstractUIRenderer::End(void) {
	// UI�̊�b�f�[�^���擾
	const auto& transform = ui_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = ui_->GetParent();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = ui_->GetRenderCanvas();

	// �g�p����s�N�Z���V�F�[�_�[���擾
	const auto pixelShader = ui_->GetUsingPixelShader();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = ui_->GetCanvasRenderOffset();

	if (parent.lock() != nullptr) {
		if (useLocalPos_) {
			renderCanvas.lock()->Draw(
				transform.localPos_ + offset,
				transform.currentScl_,
				transform.currentRot_,
				nullptr
			);
		}
		else {
			renderCanvas.lock()->Draw(
				transform.currentPos_ + offset,
				transform.currentScl_,
				transform.currentRot_,
				nullptr
			);
		}
	}
	else {
		pixelShader.lock()->SetUseTexture(0, renderCanvas.lock()->GetHandle());
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			transform.currentScl_,
			transform.currentRot_,
			nullptr
		);
	}
}
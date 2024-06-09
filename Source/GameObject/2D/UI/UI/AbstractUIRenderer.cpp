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

	// ���_�̎�ނ̉����Ďg�p
	auto offset = ui_->GetCanvasRenderOffset();
	
	// �`��X�N���[���̐ݒ�
	SetDrawScreen(defaultScreenHadle_);

	// �eUI�����邩�ǂ����`�悷����W�ƃX�P�[���l��ς���
	if (parent.lock() != nullptr) {
		// ���[�J�����W���g�p����ꍇ�̓X�P�[���l��1.0�ŌŒ肷��(�eUI�̃X�N���[���ŃX�P�[�����O����\�������邽��)
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
				transform.currentScl_,
				transform.currentRot_,
				nullptr
			);
		}
	}
	else {
		if (ui_->IsHighlighted()) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			transform.currentScl_,
			transform.currentRot_,
			nullptr
		);
		if (ui_->IsHighlighted()) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	/*auto collider = std::dynamic_pointer_cast<RectCollider>(ui_->GetCollider().lock());
	if (collider == nullptr) return;
	DrawBox(
		collider->GetCenterPos().x - collider->GetSize().x,
		collider->GetCenterPos().y - collider->GetSize().y,
		collider->GetCenterPos().x + collider->GetSize().x,
		collider->GetCenterPos().y + collider->GetSize().y,
		0xFF0000,
		false
	);*/
}

bool AbstractUIRenderer::IsDeleted(void) const {
	return ui_->IsDeleted();
}

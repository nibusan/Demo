#include <DxLib.h>
#include "UI_ImageRenderer.h"
#include "UI_Image.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ImageRenderer::UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage) : uiImage_(uiImage) {}

void UI_ImageRenderer::Render(void) {
	// ���̕`��p�X�N���[����ޔ�����
	const auto preRenderScreen = GetDrawScreen();

	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiImage_->GetRenderCanvas();
	
	// UI�̊�b�f�[�^���擾
	const auto& transform = uiImage_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiImage_->GetParent();

	// �`��X�N���[����UI�`��p�L�����o�X�ɐ؂�ւ���
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();

	uiImage_->GetImage().lock()->Draw(Vector2<float>(0.0f, 0.0f), false, nullptr);
	
	// �f�o�b�O�p
	DebugRender();

	SetDrawScreen(preRenderScreen);

	auto offset = uiImage_->GetCanvasRenderOffset();

	// 
	renderCanvas.lock()->Draw(parent.lock() == nullptr ? transform.currentPos_ + offset : transform.localPos_ + offset, 1.0f,transform.currentRot_, nullptr);

}

void UI_ImageRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = uiImage_->GetRenderCanvas();

	// �f�o�b�O�p�̃{�b�N�X
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFF0000,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFF0000
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0xFF0000
	);
}

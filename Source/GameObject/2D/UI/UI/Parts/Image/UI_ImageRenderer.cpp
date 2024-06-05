#include <DxLib.h>
#include "UI_ImageRenderer.h"
#include "UI_Image.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ImageRenderer::UI_ImageRenderer(bool useLocalPos, std::shared_ptr<UI_Image> uiImage) : AbstractUIRenderer(useLocalPos, uiImage) {}

void UI_ImageRenderer::Render(void) {
	// �g�p����s�N�Z���V�F�[�_�[���擾
	const auto pixelShader = ui_->GetUsingPixelShader();

	// �`�揈��
	const auto uiImage = std::dynamic_pointer_cast<UI_Image>(ui_);
	uiImage->GetImage().lock()->Draw(Vector2<float>(0.0f, 0.0f), false, pixelShader.lock());
	
	// �f�o�b�O�p
	//DebugRender();
}

void UI_ImageRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = ui_->GetRenderCanvas();

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

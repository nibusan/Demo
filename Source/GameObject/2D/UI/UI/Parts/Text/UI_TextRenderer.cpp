#include <DxLib.h>
#include "UI_Text.h"
#include "../../../../../../GameObject/Transform.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Common/Handle/Font/Font.h"
#include "../../../../Collider/RectCollider.h"
#include "UI_TextRenderer.h"

UI_TextRenderer::UI_TextRenderer(bool useLocalPos, std::shared_ptr<UI_Text> uiText) : AbstractUIRenderer(useLocalPos, uiText) {}

void UI_TextRenderer::Render(void) {
	// �`�揈��
	const auto uiText = std::dynamic_pointer_cast<UI_Text>(ui_);
	uiText->GetFont().lock()->Draw(Vector2<float>(0.0f, 0.0f), uiText->GetText(), uiText->GetTextColor());

	// �f�o�b�O�p
	//DebugRender();
}

void UI_TextRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = ui_->GetRenderCanvas();

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

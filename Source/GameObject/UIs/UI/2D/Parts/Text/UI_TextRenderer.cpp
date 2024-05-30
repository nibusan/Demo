#include <DxLib.h>
#include "UI_TextRenderer.h"
#include "UI_Text.h"
#include "../../../../../../GameObject/Transform.h"
#include "../../../../../../Common/Handle/Font/Font.h"

UI_TextRenderer::UI_TextRenderer(std::shared_ptr<UI_Text> uiText) : uiText_(uiText) {}

void UI_TextRenderer::Render(void) {
	// UI�̊�b�f�[�^���擾
	const auto& transform = uiText_->GetTransform();

	// �e�I�u�W�F�N�g���擾
	const auto& parent = uiText_->GetParent();

	uiText_->GetFont().lock()->Draw(
		parent.lock() == nullptr ? transform.currentPos_ : transform.localPos_,
		uiText_->GetText(),
		uiText_->GetTextColor()
	);
}

void UI_TextRenderer::DebugRender(void) {}

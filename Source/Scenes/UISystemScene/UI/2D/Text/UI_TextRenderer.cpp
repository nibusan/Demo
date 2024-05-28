#include <DxLib.h>
#include "UI_TextRenderer.h"
#include "UI_Text.h"
#include "../../../../../GameObject/Transform.h"

UI_TextRenderer::UI_TextRenderer(std::shared_ptr<UI_Text> uiText) : uiText_(uiText) {}

void UI_TextRenderer::Render(void) {
	const auto& transform = uiText_->GetTransform();
	DrawString(
		static_cast<int>(transform.pos_.x),
		static_cast<int>(transform.pos_.y),
		"Aiueo",
		0xFF0000
	);
}

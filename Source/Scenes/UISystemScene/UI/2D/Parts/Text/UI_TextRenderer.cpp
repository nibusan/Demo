#include <DxLib.h>
#include "UI_TextRenderer.h"
#include "UI_Text.h"
#include "../../../../../../GameObject/Transform.h"
#include "../../../../../../Common/Handle/Font/Font.h"

UI_TextRenderer::UI_TextRenderer(std::shared_ptr<UI_Text> uiText) : uiText_(uiText) {}

void UI_TextRenderer::Render(void) {
	const auto& transform = uiText_->GetTransform();
	DrawStringToHandle(
		static_cast<int>(transform.currentPos_.x),
		static_cast<int>(transform.currentPos_.y),
		uiText_->GetText().c_str(),
		uiText_->GetTextColor(),
		uiText_->GetFont().lock()->GetHandle()
	);
}

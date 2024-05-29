#include "UI_ButtonRenderer.h"
#include "UI_Button.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

UI_ButtonRenderer::UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton) : uiButton_(uiButton) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(uiButton_->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(uiButton_->GetUIText().lock());
}

void UI_ButtonRenderer::Render(void) {
	// ‚»‚ê‚¼‚ê‚ÌUI‚ð•`‰æ‚·‚é
	imageRenderer_->Render();
	textRenderer_->Render();
}

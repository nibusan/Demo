#include "UI_UISystemMenuRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"
#include "../Button/UI_ButtonRenderer.h"

UI_UISystemMenuRenderer::UI_UISystemMenuRenderer(bool useLocalPos, std::shared_ptr<UI_UISystemMenu> uiSystemMemu) :
AbstractUIRenderer(useLocalPos, uiSystemMemu) {
	const auto _uiSystemMemu = std::dynamic_pointer_cast<UI_UISystemMenu>(uiSystemMemu);
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, _uiSystemMemu->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(true, _uiSystemMemu->GetUIText().lock());
	const auto& buttonList = _uiSystemMemu->GetUIButtons();
	for (int i = 0; i < UI_UISystemMenu::BUTTON_COUNT; i++) {
		buttonRenderers_[i] = std::make_unique<UI_ButtonRenderer>(true, buttonList[i]);
	}
}

void UI_UISystemMenuRenderer::Render(void) {
	// それぞれのUIを描画する
	imageRenderer_->Begin();
	imageRenderer_->Render();
	textRenderer_->Begin();
	textRenderer_->Render();
	textRenderer_->End();
	for (const auto& buttonRenderer : buttonRenderers_) {
		buttonRenderer->Begin();
		buttonRenderer->Render();
		buttonRenderer->End();
	}
	imageRenderer_->End();

	// デバッグ用
	DebugRender();
}

void UI_UISystemMenuRenderer::DebugRender(void) {

}

#include <DxLib.h>
#include "UI_ButtonRenderer.h"
#include "UI_Button.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_Text.h"
#include "../../Parts/Text/UI_TextRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ButtonRenderer::UI_ButtonRenderer(bool useLocalPos, const std::shared_ptr<UI_Button> uiButton) : 
AbstractUIRenderer(useLocalPos, uiButton) {
	const auto _uiButton = std::dynamic_pointer_cast<UI_Button>(uiButton);
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, _uiButton->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(true, _uiButton->GetUIText().lock());
}

void UI_ButtonRenderer::Render(void) {
	// それぞれのUIを描画する
	imageRenderer_->Begin();
	imageRenderer_->Render();
	imageRenderer_->End();
	textRenderer_->Begin();
	textRenderer_->Render();
	textRenderer_->End();
	
	// デバッグ用
	DebugRender();
}

void UI_ButtonRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = ui_->GetRenderCanvas();
	
	// デバッグ用のボックス
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFFFF00,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0xFFFF00
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0xFFFF00
	);
}

#include <DxLib.h>
#include "UI_ButtonRenderer.h"
#include "UI_Button.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ButtonRenderer::UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton) : uiButton_(uiButton) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(uiButton_->GetUIImage().lock());
	textRenderer_ = std::make_unique<UI_TextRenderer>(uiButton_->GetUIText().lock());
}

void UI_ButtonRenderer::Render(void) {
	// 元の描画用スクリーンを退避する
	const auto preRenderScreen = GetDrawScreen();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiButton_->GetRenderCanvas();

	// UIの基礎データを取得
	const auto& transform = uiButton_->GetTransform();

	// 親オブジェクトを取得
	const auto& parent = uiButton_->GetParent();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();

	// それぞれのUIを描画する
	imageRenderer_->Render();
	textRenderer_->Render();

	// デバッグ用
	DebugRender();

	SetDrawScreen(preRenderScreen);
	renderCanvas.lock()->Draw(parent.lock() == nullptr ? transform.currentPos_ : transform.localPos_, false, nullptr);
}

void UI_ButtonRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiButton_->GetRenderCanvas();
	
	// デバッグ用のボックス
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

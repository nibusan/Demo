#include <DxLib.h>
#include "UI_TextRenderer.h"
#include "UI_Text.h"
#include "../../../../../../GameObject/Transform.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Common/Handle/Font/Font.h"

UI_TextRenderer::UI_TextRenderer(std::shared_ptr<UI_Text> uiText) : uiText_(uiText) {}

void UI_TextRenderer::Render(void) {
	// 元の描画用スクリーンを退避する
	const auto preRenderScreen = GetDrawScreen();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiText_->GetRenderCanvas();

	// UIの基礎データを取得
	const auto& transform = uiText_->GetTransform();

	// 親オブジェクトを取得
	const auto& parent = uiText_->GetParent();

	// 描画スクリーンをUI描画用キャンバスに切り替える
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();

	uiText_->GetFont().lock()->Draw(Vector2<float>(0.0f, 0.0f), uiText_->GetText(), uiText_->GetTextColor());

	// デバッグ用
	DebugRender();

	SetDrawScreen(preRenderScreen);

	auto offset = uiText_->GetCanvasRenderOffset();

	// 
	renderCanvas.lock()->Draw(parent.lock() == nullptr ? transform.currentPos_ + offset : transform.localPos_ + offset, 1.0f,transform.currentRot_, nullptr);
}

void UI_TextRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiText_->GetRenderCanvas();

	// デバッグ用のボックス
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

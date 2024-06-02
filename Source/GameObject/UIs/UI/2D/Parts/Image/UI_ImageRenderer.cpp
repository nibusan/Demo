#include <DxLib.h>
#include "UI_ImageRenderer.h"
#include "UI_Image.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ImageRenderer::UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage) : uiImage_(uiImage) {}

void UI_ImageRenderer::Render(void) {
	// 元の描画用スクリーンを退避する
	const auto preRenderScreen = GetDrawScreen();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiImage_->GetRenderCanvas();
	
	// UIの基礎データを取得
	const auto& transform = uiImage_->GetTransform();

	// 親オブジェクトを取得
	const auto& parent = uiImage_->GetParent();

	// 描画スクリーンをUI描画用キャンバスに切り替える
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();

	uiImage_->GetImage().lock()->Draw(Vector2<float>(0.0f, 0.0f), false, nullptr);
	
	// デバッグ用
	DebugRender();

	SetDrawScreen(preRenderScreen);

	auto offset = uiImage_->GetCanvasRenderOffset();

	// 
	renderCanvas.lock()->Draw(parent.lock() == nullptr ? transform.currentPos_ + offset : transform.localPos_ + offset, 1.0f,transform.currentRot_, nullptr);

}

void UI_ImageRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiImage_->GetRenderCanvas();

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

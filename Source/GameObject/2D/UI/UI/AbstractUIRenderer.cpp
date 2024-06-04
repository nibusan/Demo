#include "../../../../Renderer/AbstractRenderer.h"
#include "AbstractUI.h"
#include "AbstractUIRenderer.h"

AbstractUIRenderer::AbstractUIRenderer(bool useLocalPos, std::shared_ptr<AbstractUI> ui) : 
AbstractRenderer(useLocalPos),
ui_(ui) {}

void AbstractUIRenderer::Begin(void) {
	// 元の描画用スクリーンを退避する
	defaultScreenHadle_ = GetDrawScreen();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = ui_->GetRenderCanvas();

	// 描画スクリーンをUI描画用キャンバスに切り替える
	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void AbstractUIRenderer::End(void) {
	// UIの基礎データを取得
	const auto& transform = ui_->GetTransform();

	// 親オブジェクトを取得
	const auto& parent = ui_->GetParent();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = ui_->GetRenderCanvas();

	// 使用するピクセルシェーダーを取得
	const auto pixelShader = ui_->GetUsingPixelShader();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = ui_->GetCanvasRenderOffset();

	if (parent.lock() != nullptr) {
		if (useLocalPos_) {
			renderCanvas.lock()->Draw(
				transform.localPos_ + offset,
				transform.currentScl_,
				transform.currentRot_,
				nullptr
			);
		}
		else {
			renderCanvas.lock()->Draw(
				transform.currentPos_ + offset,
				transform.currentScl_,
				transform.currentRot_,
				nullptr
			);
		}
	}
	else {
		pixelShader.lock()->SetUseTexture(0, renderCanvas.lock()->GetHandle());
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			transform.currentScl_,
			transform.currentRot_,
			nullptr
		);
	}
}
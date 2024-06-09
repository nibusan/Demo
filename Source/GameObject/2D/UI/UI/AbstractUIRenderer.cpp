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

	// 原点の種類の応じて使用
	auto offset = ui_->GetCanvasRenderOffset();
	
	// 描画スクリーンの設定
	SetDrawScreen(defaultScreenHadle_);

	// 親UIがいるかどうか描画する座標とスケール値を変える
	if (parent.lock() != nullptr) {
		// ローカル座標を使用する場合はスケール値は1.0で固定する(親UIのスクリーンでスケーリングする可能性があるため)
		if (useLocalPos_) {
			renderCanvas.lock()->Draw(
				transform.localPos_ + offset,
				1.0f,
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
		if (ui_->IsHighlighted()) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			transform.currentScl_,
			transform.currentRot_,
			nullptr
		);
		if (ui_->IsHighlighted()) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	/*auto collider = std::dynamic_pointer_cast<RectCollider>(ui_->GetCollider().lock());
	if (collider == nullptr) return;
	DrawBox(
		collider->GetCenterPos().x - collider->GetSize().x,
		collider->GetCenterPos().y - collider->GetSize().y,
		collider->GetCenterPos().x + collider->GetSize().x,
		collider->GetCenterPos().y + collider->GetSize().y,
		0xFF0000,
		false
	);*/
}

bool AbstractUIRenderer::IsDeleted(void) const {
	return ui_->IsDeleted();
}

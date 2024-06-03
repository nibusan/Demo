#include <DxLib.h>
#include "UI_Inventory.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "UI_InventoryRenderer.h"


UI_InventoryRenderer::UI_InventoryRenderer(
	bool useLocalPos, 
	const std::shared_ptr<UI_Inventory> uiInventory) :
AbstractRenderer(useLocalPos),
uiInventory_(uiInventory) {
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, uiInventory_->GetUIImage().lock());
}

void UI_InventoryRenderer::Begin(void) {
	// 元の描画用スクリーンを退避する
	defaultScreenHadle_ = GetDrawScreen();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiInventory_->GetRenderCanvas();

	SetDrawScreen(renderCanvas.lock()->GetHandle());
	ClearDrawScreen();
}

void UI_InventoryRenderer::Render(void) {
	// それぞれのUIを描画する
	imageRenderer_->Begin();
	imageRenderer_->Render();
	imageRenderer_->End();

	// デバッグ用
	DebugRender();
}

void UI_InventoryRenderer::End(void) {
	// UIの基礎データを取得
	const auto& transform = uiInventory_->GetTransform();

	// 親オブジェクトを取得
	const auto& parent = uiInventory_->GetParent();

	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiInventory_->GetRenderCanvas();

	SetDrawScreen(defaultScreenHadle_);

	auto offset = uiInventory_->GetCanvasRenderOffset();

	if (parent.lock() != nullptr) {
		if (useLocalPos_) {
			renderCanvas.lock()->Draw(
				transform.localPos_ + offset,
				8.0f,
				transform.currentRot_,
				nullptr
			);
		}
		else {
			renderCanvas.lock()->Draw(
				transform.currentPos_ + offset,
				8.0f,
				transform.currentRot_,
				nullptr
			);
		}
	}
	else {
		renderCanvas.lock()->Draw(
			transform.currentPos_ + offset,
			8.0f,
			transform.currentRot_,
			nullptr
		);
	}
}

void UI_InventoryRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = uiInventory_->GetRenderCanvas();

	// デバッグ用のボックス
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FFFF,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FFFF
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0x00FFFF
	);
}

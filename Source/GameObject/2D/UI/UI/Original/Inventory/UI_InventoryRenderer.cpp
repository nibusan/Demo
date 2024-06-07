#include <DxLib.h>
#include "UI_Inventory.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "UI_Inventory.h"
#include "UI_InventoryRenderer.h"


UI_InventoryRenderer::UI_InventoryRenderer(bool useLocalPos, std::shared_ptr<UI_Inventory> uiInventory) :
AbstractUIRenderer(useLocalPos, uiInventory) {
	const auto _uiInventory = std::dynamic_pointer_cast<UI_Inventory>(uiInventory);
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, _uiInventory->GetBackGround_UIImage().lock());
}

void UI_InventoryRenderer::Render(void) {
	// それぞれのUIを描画する
	imageRenderer_->Begin();
	imageRenderer_->Render();
	imageRenderer_->End();

	// デバッグ用
	DebugRender();
}

void UI_InventoryRenderer::DebugRender(void) {
	// UIの描画用キャンバスを取得
	const auto& renderCanvas = ui_->GetRenderCanvas();

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

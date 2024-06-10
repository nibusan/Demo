#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_ImageRenderer;
class UI_Inventory;
class UI_InventoryRenderer : public AbstractUIRenderer {
public:
	UI_InventoryRenderer(void) = default;
	virtual ~UI_InventoryRenderer(void) override = default;

	/// @brief コンストラクタ
	/// @param uiInventory 描画するインベントリのUI
	UI_InventoryRenderer(bool useLocalPos, std::shared_ptr<UI_Inventory> uiInventory);

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// インベントリを描画するための部品
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;

};


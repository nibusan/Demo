#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Inventory;
class UI_InventoryRenderer : public AbstractRenderer {
public:
	UI_InventoryRenderer(void) = default;
	~UI_InventoryRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiButton 描画するインベントリのUI
	UI_InventoryRenderer(bool useLocalPos, const std::shared_ptr<UI_Inventory> uiInventory);

	/// @brief 描画開始処理
	virtual void Begin(void) override;

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画終了処理 
	virtual void End(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するボタンのUI
	std::shared_ptr<UI_Inventory> uiInventory_;

	// インベントリを描画するための部品
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;

};


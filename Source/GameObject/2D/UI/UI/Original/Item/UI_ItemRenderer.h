#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Item;
class UI_ItemRenderer : public AbstractUIRenderer {
public:
	UI_ItemRenderer(void) = default;
	virtual ~UI_ItemRenderer(void) override = default;

	/// @brief コンストラクタ
	/// @param uiInventory 描画するアイテムのUI
	UI_ItemRenderer(bool useLocalPos, std::shared_ptr<UI_Item> uiItem);

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
};
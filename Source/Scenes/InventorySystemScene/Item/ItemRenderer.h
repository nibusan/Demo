#pragma once
#include <memory>
#include "../../../Renderer/AbstractRenderer.h"

/// @brief アイテムを描画するためのクラス
class Item;
class Graphic;
class ItemRenderer : public AbstractRenderer {
public:
	ItemRenderer(void) = default;
	~ItemRenderer(void) override = default;

	/// @brief コンストラクタ
	/// @param inventory 描画するインベントリ
	ItemRenderer(std::shared_ptr<Item> item);

	/// @brief 描画開始処理
	virtual void Begin(void) override;

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画終了処理 
	virtual void End(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するアイテム
	std::shared_ptr<Item> item_;

	// 描画するアイテムに紐づいた画像
	std::unique_ptr<Graphic> image_;
};
#pragma once
#include <memory>
#include "../../../Renderer/IRenderer.h"

/// @brief アイテムを描画するためのクラス
class Item;
class Graphic;
class ItemRenderer : public IRenderer {
public:
	ItemRenderer(void) = default;
	~ItemRenderer(void) override = default;

	/// @brief コンストラクタ
	/// @param inventory 描画するインベントリ
	ItemRenderer(std::shared_ptr<Item> item);

	/// @brief アイテムの描画処理
	void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するアイテム
	std::shared_ptr<Item> item_;

	// 描画するアイテムに紐づいた画像
	std::unique_ptr<Graphic> image_;
};
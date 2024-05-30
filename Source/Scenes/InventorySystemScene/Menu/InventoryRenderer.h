#pragma once
#include <memory>
#include <DxLib.h>
#include "../../../Renderer/IRenderer.h"

/// @brief インベントリを描画するためのクラス
/// @brief 今回はItemクラスを使用する前提で設計してます
template <typename T>
class Inventory;
class Item;
class InventoryRenderer : public IRenderer {
public:
	InventoryRenderer(void) = default;
	~InventoryRenderer(void) override = default;
	
	/// @brief コンストラクタ
	/// @param inventory 描画するインベントリ
	InventoryRenderer(std::shared_ptr<Inventory<Item>> inventory);

	/// @brief 描画処理  
	void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// インベントリのデータ
	std::shared_ptr<Inventory<Item>> inventory_;
};
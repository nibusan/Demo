#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief アイテムUIのクラスです
class Item;
class UI_Item : public AbstractUI {
public:
	UI_Item(void) = default;
	virtual ~UI_Item(void) override = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	UI_Item(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		std::weak_ptr<Graphic> image,
		std::weak_ptr<Item> item
	);

	/// @brief 参照元のアイテムを返す 
	/// @return アイテム
	std::weak_ptr<Item> GetItem(void);

	/// @brief アイテムの画像を返す 
	/// @return アイテムの画像
	std::weak_ptr<Graphic> GetItemImage(void);
private:
	// 描画するアイテム
	std::weak_ptr<Item> item_;

	// 描画する画像
	std::weak_ptr<Graphic> image_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};
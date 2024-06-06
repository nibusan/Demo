#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief インベントリUIのクラスです
class UI_Image;
template <typename T>
class Inventory;
class Item;
class UI_Inventory : public AbstractUI {
public:
	UI_Inventory(void);
	~UI_Inventory(void) = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	UI_Inventory(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		std::shared_ptr<Inventory<Item>> inventory,
		const std::shared_ptr<UI_Image>& uiImage
	);

	/// @brief 参照元のインベントリを返す 
	/// @return インベントリ
	std::weak_ptr<Inventory<Item>> GetInventory(void);

	/// @brief 背景画像部分のUIを返す 
	/// @return 背景画像部分のUI
	std::weak_ptr<UI_Image> GetUIImage(void);

private:
	// 参照元のインベントリ
	std::shared_ptr<Inventory<Item>> inventory_;

	// 背景画像部分のUI
	std::shared_ptr<UI_Image> uiImage_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UIを長押ししている時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickDown(void) override;

	/// @brief UIを離した時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickUp(void) override;
};


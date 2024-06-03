#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief ボタンUIのクラスです
class UI_Image;
class UI_Text;
class UI_Button : public AbstractUI {
public:
	UI_Button(void);
	~UI_Button(void) = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	/// @param uiText ベースとなるテキストのUI
	UI_Button(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType, 
		const std::shared_ptr<UI_Image>& uiImage, 
		const std::shared_ptr<UI_Text>& uiText
	);

	/// @brief 背景画像部分のUIを返す 
	/// @return 背景画像部分のUI
	std::weak_ptr<UI_Image> GetUIImage(void);
	
	/// @brief テキスト部分のUIを返す
	/// @return テキスト部分のUI
	std::weak_ptr<UI_Text> GetUIText(void);
private:
	// 背景画像部分のUI
	std::shared_ptr<UI_Image> uiImage_;

	// テキスト部分のUI
	std::shared_ptr<UI_Text> uiText_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UIを長押ししている時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickDown(void) override;

	/// @brief UIを離した時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickUp(void) override;
};


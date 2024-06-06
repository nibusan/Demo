#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief テキストのUIのクラスです
class Font;
class UI_Text : public AbstractUI {
public:
	UI_Text(void);
	~UI_Text(void) = default;

	UI_Text(
		const Vector2<float>& canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID,
		std::shared_ptr<Font> font, 
		const std::string& text, 
		unsigned int color
	);

	/// @brief 描画する際に使用するフォントを返す 
	/// @return フォント
	std::weak_ptr<Font> GetFont(void) const;

	/// @brief 描画するテキストを返す 
	/// @return テキスト
	std::string GetText(void) const;

	/// @brief 描画するテキストの色を返す 
	/// @return 色
	unsigned int GetTextColor(void) const;
private:
	// 使用するフォント
	std::shared_ptr<Font> font_;

	// 描画するテキスト
	std::string text_;

	// テキストの色
	unsigned int textColor_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


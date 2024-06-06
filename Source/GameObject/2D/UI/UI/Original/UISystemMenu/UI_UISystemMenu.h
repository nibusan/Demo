#pragma once
#include <array>
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief テキストのUIのクラスです
class UI_Image;
class UI_Text;
class UI_Button;
class UI_UISystemMenu : public AbstractUI {
public:
	static constexpr int BUTTON_COUNT = 4;

	UI_UISystemMenu(void);
	~UI_UISystemMenu(void) = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	/// @param uiText ベースとなるテキストのUI
	UI_UISystemMenu(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		const std::shared_ptr<UI_Image>& backGround, 
		const std::shared_ptr<UI_Text>& title,
		const std::shared_ptr<UI_Button>& button1,
		const std::shared_ptr<UI_Button>& button2,
		const std::shared_ptr<UI_Button>& button3,
		const std::shared_ptr<UI_Button>& button4
	);

	/// @brief 背景画像部分のUIを返す 
	/// @return 背景画像部分のUI
	std::weak_ptr<UI_Image> GetUIImage(void);

	/// @brief タイトル部分のUIを返す 
	/// @return タイトル部分のUI
	std::weak_ptr<UI_Text> GetUIText(void);

	/// @brief テキスト部分のUIを返す
	/// @return テキスト部分のUI
	[[nodiscard]] const std::array<std::shared_ptr<UI_Button>, BUTTON_COUNT>& GetUIButtons(void);
private:
	// 背景画像部分のUI
	std::shared_ptr<UI_Image> uiImage_BackGround_;

	// メニューのタイトル
	std::shared_ptr<UI_Text> uiText_Title_;

	// ボタン部分のUI
	std::array<std::shared_ptr<UI_Button>, BUTTON_COUNT> buttonList_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


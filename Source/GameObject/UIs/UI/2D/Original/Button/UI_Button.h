#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

/// @brief テキストのUIのクラスです
class UI_Image;
class UI_Text;
class UI_Button : public AbstractUI {
public:
	UI_Button(void) = default;
	~UI_Button(void) = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	/// @param uiText ベースとなるテキストのUI
	UI_Button(const std::shared_ptr<UI_Image>& uiImage, const std::shared_ptr<UI_Text>& uiText);

	std::weak_ptr<UI_Image> GetUIImage(void);
	std::weak_ptr<UI_Text> GetUIText(void);
private:
	// 使用するフォント
	std::shared_ptr<UI_Image> uiImage_;
	std::shared_ptr<UI_Text> uiText_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


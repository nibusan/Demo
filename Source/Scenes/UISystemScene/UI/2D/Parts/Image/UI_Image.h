#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

class Graphic;
class UI_Image : public AbstractUI {
public:
	UI_Image(void) = default;
	~UI_Image(void) = default;

	/// @brief コンストラクタ
	/// @param image 描画する画像
	UI_Image(std::shared_ptr<Graphic> image);

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	std::weak_ptr<Graphic> GetImage(void);
private:
	// 描画する画像
	std::shared_ptr<Graphic> image_;

	/// @brief 強調表示されてる時の更新処理 
	void HighlightUpdate(void) override;
};


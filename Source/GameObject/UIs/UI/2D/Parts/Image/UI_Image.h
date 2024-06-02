#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

class Graphic;
class UI_Image : public AbstractUI {
public:
	UI_Image(void);
	~UI_Image(void) = default;

	/// @brief コンストラクタ
	/// @param canvasSize UIのキャンバスのサイズ
	/// @param image 描画する画像
	UI_Image(
		const Vector2<float>& canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		std::weak_ptr<Graphic> image
	);

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	std::weak_ptr<Graphic> GetImage(void);
private:
	// 描画する画像
	std::weak_ptr<Graphic> image_;

	/// @brief 強調表示されてる時の更新処理 
	void HighlightUpdate(void) override;
};


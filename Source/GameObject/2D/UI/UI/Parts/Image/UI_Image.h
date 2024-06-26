#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

class Graphic;
class UI_Image : public AbstractUI {
public:
	UI_Image(void);
	virtual ~UI_Image(void) override = default;

	/// @brief コンストラクタ
	/// @param canvasSize UIのキャンバスのサイズ
	/// @param image 描画する画像
	UI_Image(
		const Vector2<float>& canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID,
		std::weak_ptr<Graphic> image
	);

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief 描画する画像を返す 
	/// @return 画像
	std::weak_ptr<Graphic> GetImage(void);
protected:
	// 描画する画像
	std::weak_ptr<Graphic> image_;

	/// @brief 強調表示されてる時の更新処理 
	void HighlightUpdate(void) override;
};


#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief スライダーUIのクラスです
class UI_Image;
class UI_Slider : public AbstractUI {
public:
	UI_Slider(void);
	virtual ~UI_Slider(void) override = default;

	/// @brief コンストラクタ
	/// @param uiImage ベースとなる画像のUI
	/// @param uiText ベースとなるテキストのUI
	UI_Slider(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		const std::shared_ptr<UI_Image>& uiImage_BaseImage,
		const std::shared_ptr<UI_Image>& uiImage_CircleImage,
		const std::shared_ptr<UI_Image>& uiImage_GaugeImage,
		float min,
		float max
	);

	/// @brief 背景画像部分のUIを返す 
	/// @return 背景画像部分のUI
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_BaseImage(void);
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_CircleImage(void);
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_GaugeImage(void);

	/// @brief スライダーが管理する値の最小値を返す
	/// @return 最小値
	float GetMinValue(void) const;
	
	/// @brief スライダーが管理する値の最大値を返す
	/// @return 最大値
	float GetMaxValue(void) const;

	/// @brief スライダーが管理する現在の値を返す 
	/// @return 現在の値
	float GetCurrentValue(void) const;
private:
	// 背景画像部分のUI
	std::shared_ptr<UI_Image> uiImage_BaseImage_;
	std::shared_ptr<UI_Image> uiImage_CircleImage_;
	std::shared_ptr<UI_Image> uiImage_GaugeImage_;

	// スライダーが扱う値の最小値
	float min_;

	// スライダーが扱う値の最大値
	float max_;

	// スライダーの現在の値
	float currentValue_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UIを長押ししている時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickDown(void) override;
};


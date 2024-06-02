#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"

class UI_Image;
class UI_ImageRenderer : public AbstractRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage);

	/// @brief 描画開始処理
	virtual void Begin(void) override;

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画終了処理 
	virtual void End(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するTextのUI
	std::shared_ptr<UI_Image> uiImage_;

};


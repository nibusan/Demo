#pragma once
#include <memory>
#include "../../../../../../Renderer/IRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Button;
class UI_ButtonRenderer : public IRenderer {
public:
	UI_ButtonRenderer(void) = default;
	~UI_ButtonRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiButton 描画するボタンのUI
	UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton);

	/// @brief 描画処理
	void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するボタンのUI
	std::shared_ptr<UI_Button> uiButton_;

	// ボタンを描画するための部品
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;

};


#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../Original/Button/UI_ButtonRenderer.h"
#include "../../Original/UISystemMenu/UI_UISystemMenu.h"

class UI_ImageRenderer;
class UI_TextRenderer;
class UI_UISystemMenuRenderer : public AbstractRenderer {
public:
	UI_UISystemMenuRenderer(void) = default;
	~UI_UISystemMenuRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiButton 描画するボタンのUI
	UI_UISystemMenuRenderer(bool useLocalPos, const std::shared_ptr<UI_UISystemMenu>& uiSystemMenu);

	/// @brief 描画開始処理
	virtual void Begin(void) override;

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画終了処理 
	virtual void End(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するメニューのUI
	std::shared_ptr<UI_UISystemMenu> uiSystemMenu_;

	// ボタンを描画するための部品
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;
	std::array<std::unique_ptr<UI_ButtonRenderer>, UI_UISystemMenu::BUTTON_COUNT> buttonRenderers_;

};


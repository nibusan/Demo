#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"
#include "UI_UISystemMenu.h"

class UI_ImageRenderer;
class UI_TextRenderer;
class UI_ButtonRenderer;
class UI_UISystemMenu;
class UI_UISystemMenuRenderer : public AbstractUIRenderer {
public:
	UI_UISystemMenuRenderer(void) = default;
	~UI_UISystemMenuRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiSystemMemu 描画するメニューのUI
	UI_UISystemMenuRenderer(bool useLocalPos, std::shared_ptr<UI_UISystemMenu> uiSystemMemu);

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// ボタンを描画するための部品
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;
	std::array<std::unique_ptr<UI_ButtonRenderer>, UI_UISystemMenu::BUTTON_COUNT> buttonRenderers_;

};


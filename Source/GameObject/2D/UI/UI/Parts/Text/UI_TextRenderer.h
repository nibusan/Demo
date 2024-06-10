#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Text;
class UI_TextRenderer : public AbstractUIRenderer {
public:
	UI_TextRenderer(void) = default;
	virtual ~UI_TextRenderer(void) override = default;
	
	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_TextRenderer(bool useLocalPos, std::shared_ptr<UI_Text> uiText);

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;

};


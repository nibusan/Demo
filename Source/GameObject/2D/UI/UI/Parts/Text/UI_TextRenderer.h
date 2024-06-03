#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"

class UI_Text;
class UI_TextRenderer : public AbstractRenderer {
public:
	UI_TextRenderer(void) = default;
	~UI_TextRenderer(void) = default;
	
	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_TextRenderer(bool useLocalPos, std::shared_ptr<UI_Text> uiText);

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
	std::shared_ptr<UI_Text> uiText_;

};


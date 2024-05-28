#pragma once
#include <memory>
#include "../../../../../Renderer/IRenderer.h"

class UI_Text;
class UI_TextRenderer : public IRenderer {
public:
	UI_TextRenderer(void) = default;
	~UI_TextRenderer(void) = default;
	
	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_TextRenderer(std::shared_ptr<UI_Text> uiText);

	/// @brief 描画処理
	void Render(void) override;
private:
	// 描画するTextのUI
	std::shared_ptr<UI_Text> uiText_;

};


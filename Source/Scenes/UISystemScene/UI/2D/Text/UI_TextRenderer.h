#pragma once
#include <memory>
#include "../../../../../Renderer/IRenderer.h"

class UI_Text;
class UI_TextRenderer : public IRenderer {
public:
	UI_TextRenderer(void) = default;
	~UI_TextRenderer(void) = default;
	
	/// @brief ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	/// @param uiText •`‰æ‚·‚éText‚ÌUI
	UI_TextRenderer(std::shared_ptr<UI_Text> uiText);

	/// @brief •`‰æˆ—
	void Render(void) override;
private:
	// •`‰æ‚·‚éText‚ÌUI
	std::shared_ptr<UI_Text> uiText_;

};


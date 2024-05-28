#pragma once
#include <memory>
#include "../../../../../../Renderer/IRenderer.h"

class UI_Image;
class UI_ImageRenderer : public IRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	/// @param uiText •`‰æ‚·‚éText‚ÌUI
	UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage);

	/// @brief •`‰æˆ—
	void Render(void) override;
private:
	// •`‰æ‚·‚éText‚ÌUI
	std::shared_ptr<UI_Image> uiImage_;

};


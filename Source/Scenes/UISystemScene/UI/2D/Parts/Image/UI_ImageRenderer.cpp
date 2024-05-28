#include <DxLib.h>
#include "UI_ImageRenderer.h"
#include "UI_Image.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"

UI_ImageRenderer::UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage) : uiImage_(uiImage) {}

void UI_ImageRenderer::Render(void) {
	const auto& transform = uiImage_->GetTransform();
	uiImage_->GetImage().lock()->Draw(transform.pos_, true, nullptr);
}

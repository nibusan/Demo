#include "ItemRenderer.h"
#include "../../../Common/Handle/Graphic/Graphic.h"

ItemRenderer::ItemRenderer(std::shared_ptr<Item> item) : item_(item) {
	image_ = std::make_unique<Graphic>("Assets/Scenes/InventorySystemScene/Item/Items.png");
}

void ItemRenderer::Render(void) {
	image_->Draw(Vector2<float>(400.0f, 400.0f), 10.0f, 0.0f, 8, 8, 2, 1, nullptr);
}

void ItemRenderer::DebugRender(void) {}

#include "../../../../../../Scenes/InventorySystemScene/Item/Item.h"
#include "UI_Item.h"
#include "UI_ItemRenderer.h"

UI_ItemRenderer::UI_ItemRenderer(bool useLocalPos, std::shared_ptr<UI_Item> uiItem) : 
AbstractUIRenderer(useLocalPos, std::dynamic_pointer_cast<AbstractUI>(uiItem)) {}

void UI_ItemRenderer::Render(void) {
	std::weak_ptr<UI_Item> uiItem = std::dynamic_pointer_cast<UI_Item>(ui_);
	const auto& item = uiItem.lock()->GetItem();
	const auto itemID = item.lock()->GetID();
	const auto& itemImage = uiItem.lock()->GetItemImage();

	itemImage.lock()->Draw(
		{ 0.0f, 0.0f },
		1.0f,
		0.0f,
		8, 8,
		itemID % 8,
		itemID == 0 ? 0 : itemID / 8,
		nullptr
	);
}

void UI_ItemRenderer::DebugRender(void) {

}

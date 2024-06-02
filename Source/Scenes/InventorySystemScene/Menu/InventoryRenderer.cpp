#include "InventoryRenderer.h"
#include "Inventory.h"

InventoryRenderer::InventoryRenderer(std::shared_ptr<Inventory<Item>> inventory) : inventory_(inventory) {

}

void InventoryRenderer::Begin(void) {}

void InventoryRenderer::Render(void) {
	for (int i = 0; i < inventory_->MAX_ITEM_SLOT_COUNT; i++) {
		DrawBox(
			300 + i * 100,
			300,
			350 + i * 100,
			350,
			0xFFFFFF,
			false
		);
	}
}

void InventoryRenderer::End(void) {}

void InventoryRenderer::DebugRender(void) {}

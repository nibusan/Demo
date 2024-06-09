#include "../../Parts/Image/UI_Image.h"
#include "../../Original/Item/UI_Item.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Scenes/InventorySystemScene/Menu/Inventory.h"
#include "../../../../../../Scenes/InventorySystemScene/Item/Item.h"
#include "../../../../../../Managers/ResourceManager.h"
#include "UI_Inventory.h"

UI_Inventory::UI_Inventory(void) {}

UI_Inventory::UI_Inventory(
	const Vector2<float> canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	bool isClickable,
	const std::function<void(void)> onClickCallBack,
	std::weak_ptr<PixelShader> usingPixelShader,
	int usingPixelShaderEventID, 
	std::shared_ptr<Inventory<Item>> inventory,
	const std::shared_ptr<UI_Image>& uiImage,
	std::weak_ptr<Graphic> itemsImage) :
AbstractUI(canvasSize, originType, isClickable, onClickCallBack, usingPixelShader, usingPixelShaderEventID),
inventory_(inventory),
uiImage_(uiImage),
itemsImage_(itemsImage) {
	uiItem_ = std::make_shared<UI_Item>(
		canvasSize,
		originType,
		isClickable,
		onClickCallBack,
		usingPixelShader,
		usingPixelShaderEventID,
		std::dynamic_pointer_cast<Graphic>(ResourceManager::GetInstance().GetResourceFile("IMAGE_UI_ITEMS").lock()),
		inventory_->GetItem(0)
	);
}

std::weak_ptr<Inventory<Item>> UI_Inventory::GetInventory(void) {
	return inventory_;
}

std::weak_ptr<UI_Image> UI_Inventory::GetBackGround_UIImage(void) {
	return uiImage_;
}

std::weak_ptr<Graphic> UI_Inventory::GetItemsImage(void) {
	return itemsImage_;
}

std::weak_ptr<UI_Item> UI_Inventory::GetUIItem(void) {
	return uiItem_;
}

void UI_Inventory::Init_UI(void) {
	// このインベントリの子として画像をセットする
	AddChild(uiImage_);
	const auto& inventoryCanvasSize = renderCanvas_->GetSize().ToVector2f();
	uiImage_->SetTransformData(
		inventoryCanvasSize / 2.0f,
		0.0f,
		1.0f
	);
}

void UI_Inventory::Update_UI(void) {

}

void UI_Inventory::Release_UI(void) {}

void UI_Inventory::OnClickDown(void) {}

void UI_Inventory::OnClickUp(void) {}

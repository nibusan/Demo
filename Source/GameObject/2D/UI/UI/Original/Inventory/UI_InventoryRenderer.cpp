#include <DxLib.h>
#include "UI_Inventory.h"
#include "../../Parts/Image/UI_Image.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../../../Scenes/InventorySystemScene/Item/Item.h"
#include "../../../../../../Scenes/InventorySystemScene/Menu/Inventory.h"
#include "UI_Inventory.h"
#include "UI_InventoryRenderer.h"


UI_InventoryRenderer::UI_InventoryRenderer(bool useLocalPos, std::shared_ptr<UI_Inventory> uiInventory) :
AbstractUIRenderer(useLocalPos, uiInventory) {
	const auto _uiInventory = std::dynamic_pointer_cast<UI_Inventory>(uiInventory);
	imageRenderer_ = std::make_unique<UI_ImageRenderer>(true, _uiInventory->GetBackGround_UIImage().lock());
}

void UI_InventoryRenderer::Render(void) {
	const auto _uiInventory = std::dynamic_pointer_cast<UI_Inventory>(ui_);

	// ���ꂼ���UI��`�悷��
	imageRenderer_->Begin();
	imageRenderer_->Render();

	// �`�悷��A�C�e���̉摜���擾
	const auto& itemsImage = _uiInventory->GetItemsImage();

	const Vector2<float> basePos = { 12.0f, 12.0f };
	const Vector2<float> offset = { 17.0f, 17.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			const auto& item = _uiInventory->GetInventory().lock()->GetItem(i * 4 + j);
			// �A�C�e�����Ȃ��ꍇ�͕`�揈�����X�L�b�v
			if (item.expired()) continue;
			const auto& itemID = item.lock()->GetID();
			const auto itemRenderPos = basePos + (offset * Vector2<float>(static_cast<float>(j), static_cast<float>(i)));
			itemsImage.lock()->Draw(
				itemRenderPos,
				1.0f,
				0.0f,
				8,
				8,
				itemID % 8,
				itemID / 8,
				nullptr
			);
		}
	}

	imageRenderer_->End();

	// �f�o�b�O�p
	//DebugRender();
}

void UI_InventoryRenderer::DebugRender(void) {
	// UI�̕`��p�L�����o�X���擾
	const auto& renderCanvas = ui_->GetRenderCanvas();

	// �f�o�b�O�p�̃{�b�N�X
	auto canvasSize = renderCanvas.lock()->GetSize();
	DrawBox(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FFFF,
		false
	);
	DrawLine(
		0,
		0,
		static_cast<int>(canvasSize.x),
		static_cast<int>(canvasSize.y),
		0x00FFFF
	);
	DrawLine(
		0,
		static_cast<int>(canvasSize.y),
		static_cast<int>(canvasSize.x),
		0,
		0x00FFFF
	);
}

#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_ImageRenderer;
class UI_Inventory;
class UI_InventoryRenderer : public AbstractUIRenderer {
public:
	UI_InventoryRenderer(void) = default;
	virtual ~UI_InventoryRenderer(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param uiInventory �`�悷��C���x���g����UI
	UI_InventoryRenderer(bool useLocalPos, std::shared_ptr<UI_Inventory> uiInventory);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �C���x���g����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;

};


#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Inventory;
class UI_InventoryRenderer : public AbstractRenderer {
public:
	UI_InventoryRenderer(void) = default;
	~UI_InventoryRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiButton �`�悷��C���x���g����UI
	UI_InventoryRenderer(bool useLocalPos, const std::shared_ptr<UI_Inventory> uiInventory);

	/// @brief �`��J�n����
	virtual void Begin(void) override;

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`��I������ 
	virtual void End(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �`�悷��{�^����UI
	std::shared_ptr<UI_Inventory> uiInventory_;

	// �C���x���g����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;

};


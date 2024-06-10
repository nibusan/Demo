#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Item;
class UI_ItemRenderer : public AbstractUIRenderer {
public:
	UI_ItemRenderer(void) = default;
	virtual ~UI_ItemRenderer(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param uiInventory �`�悷��A�C�e����UI
	UI_ItemRenderer(bool useLocalPos, std::shared_ptr<UI_Item> uiItem);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
};
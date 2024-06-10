#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Text;
class UI_TextRenderer : public AbstractUIRenderer {
public:
	UI_TextRenderer(void) = default;
	virtual ~UI_TextRenderer(void) override = default;
	
	/// @brief �R���X�g���N�^
	/// @param uiText �`�悷��Text��UI
	UI_TextRenderer(bool useLocalPos, std::shared_ptr<UI_Text> uiText);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;

};


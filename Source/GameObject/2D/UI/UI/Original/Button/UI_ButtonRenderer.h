#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Button;
class UI_ImageRenderer;
class UI_TextRenderer;
class UI_ButtonRenderer : public AbstractUIRenderer {
public:
	UI_ButtonRenderer(void) = default;
	virtual ~UI_ButtonRenderer(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param uiButton �`�悷��{�^����UI
	UI_ButtonRenderer(bool useLocalPos, const std::shared_ptr<UI_Button> uiButton);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �{�^����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;

};


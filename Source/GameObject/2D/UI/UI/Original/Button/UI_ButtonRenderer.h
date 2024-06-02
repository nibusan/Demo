#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Button;
class UI_ButtonRenderer : public AbstractRenderer {
public:
	UI_ButtonRenderer(void) = default;
	~UI_ButtonRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiButton �`�悷��{�^����UI
	UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton);

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
	std::shared_ptr<UI_Button> uiButton_;

	// �{�^����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;

};


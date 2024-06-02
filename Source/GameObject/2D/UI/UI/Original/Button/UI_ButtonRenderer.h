#pragma once
#include <memory>
#include "../../../../../../Renderer/IRenderer.h"
#include "../../Parts/Image/UI_ImageRenderer.h"
#include "../../Parts/Text/UI_TextRenderer.h"

class UI_Button;
class UI_ButtonRenderer : public IRenderer {
public:
	UI_ButtonRenderer(void) = default;
	~UI_ButtonRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiButton �`�悷��{�^����UI
	UI_ButtonRenderer(const std::shared_ptr<UI_Button> uiButton);

	/// @brief �`�揈��
	void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �`�悷��{�^����UI
	std::shared_ptr<UI_Button> uiButton_;

	// �{�^����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;

};


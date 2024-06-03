#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../Original/Button/UI_ButtonRenderer.h"
#include "../../Original/UISystemMenu/UI_UISystemMenu.h"

class UI_ImageRenderer;
class UI_TextRenderer;
class UI_UISystemMenuRenderer : public AbstractRenderer {
public:
	UI_UISystemMenuRenderer(void) = default;
	~UI_UISystemMenuRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiButton �`�悷��{�^����UI
	UI_UISystemMenuRenderer(bool useLocalPos, const std::shared_ptr<UI_UISystemMenu>& uiSystemMenu);

	/// @brief �`��J�n����
	virtual void Begin(void) override;

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`��I������ 
	virtual void End(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �`�悷�郁�j���[��UI
	std::shared_ptr<UI_UISystemMenu> uiSystemMenu_;

	// �{�^����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;
	std::array<std::unique_ptr<UI_ButtonRenderer>, UI_UISystemMenu::BUTTON_COUNT> buttonRenderers_;

};


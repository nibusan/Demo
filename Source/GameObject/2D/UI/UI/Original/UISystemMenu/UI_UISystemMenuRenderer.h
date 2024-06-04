#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"
#include "UI_UISystemMenu.h"

class UI_ImageRenderer;
class UI_TextRenderer;
class UI_ButtonRenderer;
class UI_UISystemMenu;
class UI_UISystemMenuRenderer : public AbstractUIRenderer {
public:
	UI_UISystemMenuRenderer(void) = default;
	~UI_UISystemMenuRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiSystemMemu �`�悷�郁�j���[��UI
	UI_UISystemMenuRenderer(bool useLocalPos, std::shared_ptr<UI_UISystemMenu> uiSystemMemu);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �{�^����`�悷�邽�߂̕��i
	std::unique_ptr<UI_ImageRenderer> imageRenderer_;
	std::unique_ptr<UI_TextRenderer> textRenderer_;
	std::array<std::unique_ptr<UI_ButtonRenderer>, UI_UISystemMenu::BUTTON_COUNT> buttonRenderers_;

};


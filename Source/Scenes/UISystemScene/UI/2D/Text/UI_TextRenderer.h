#pragma once
#include <memory>
#include "../../../../../Renderer/IRenderer.h"

class UI_Text;
class UI_TextRenderer : public IRenderer {
public:
	UI_TextRenderer(void) = default;
	~UI_TextRenderer(void) = default;
	
	/// @brief �R���X�g���N�^
	/// @param uiText �`�悷��Text��UI
	UI_TextRenderer(std::shared_ptr<UI_Text> uiText);

	/// @brief �`�揈��
	void Render(void) override;
private:
	// �`�悷��Text��UI
	std::shared_ptr<UI_Text> uiText_;

};


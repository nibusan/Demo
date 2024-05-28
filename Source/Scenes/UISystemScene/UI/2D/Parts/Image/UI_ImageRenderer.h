#pragma once
#include <memory>
#include "../../../../../../Renderer/IRenderer.h"

class UI_Image;
class UI_ImageRenderer : public IRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiText �`�悷��Text��UI
	UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage);

	/// @brief �`�揈��
	void Render(void) override;
private:
	// �`�悷��Text��UI
	std::shared_ptr<UI_Image> uiImage_;

};


#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Image;
class UI_ImageRenderer : public AbstractUIRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiText �`�悷��Text��UI
	UI_ImageRenderer(bool useLocalPos, std::shared_ptr<UI_Image> uiImage);

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;

};


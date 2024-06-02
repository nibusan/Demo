#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"

class UI_Image;
class UI_ImageRenderer : public AbstractRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiText �`�悷��Text��UI
	UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage);

	/// @brief �`��J�n����
	virtual void Begin(void) override;

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`��I������ 
	virtual void End(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �`�悷��Text��UI
	std::shared_ptr<UI_Image> uiImage_;

};


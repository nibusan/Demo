#pragma once
#include <memory>
#include "../../../../Renderer/AbstractRenderer.h"

class AbstractUI;
class AbstractUIRenderer : public AbstractRenderer {
public:
	AbstractUIRenderer(void) = default;
	~AbstractUIRenderer(void) = default;

	/// @brief �R���X�g���N�^
	/// @param useLocalPos �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	/// @param ui �`�悷��UI
	AbstractUIRenderer(bool useLocalPos, std::shared_ptr<AbstractUI> ui);

	/// @brief �`��J�n����
	virtual void Begin(void) override;

	/// @brief �`�揈�� 
	virtual void Render(void) = 0;

	/// @brief �`��I������ 
	virtual void End(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) = 0;

protected:
	// �`�悷��UI
	std::shared_ptr<AbstractUI> ui_;

};


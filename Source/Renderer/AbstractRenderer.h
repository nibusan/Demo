#pragma once
#include "../Common/Handle/Graphic/Graphic.h"

/// @brief �`��@�\��񋟂��钊�ۃN���X
class AbstractRenderer {
public:
	virtual ~AbstractRenderer(void) = default;

	/// @brief �`��J�n����
	virtual void Begin(void) = 0;

	/// @brief �`�揈�� 
	virtual void Render(void) = 0;

	/// @brief �`��I������ 
	virtual void End(void) = 0;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) = 0;

protected:
	// ���̕`��p�X�N���[���̃n���h��ID(Begin()�ł����ɑޔ�����End()�Ō��ɖ߂�)
	int defaultScreenHadle_;
};
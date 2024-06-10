#pragma once
#include <vector>
#include <memory>
#include "../Common/Handle/Graphic/Graphic.h"

/// @brief �`��@�\��񋟂��钊�ۃN���X
class AbstractRenderer : std::enable_shared_from_this<AbstractRenderer> {
public:
	AbstractRenderer(void);
	virtual ~AbstractRenderer(void) = default ;
	
	/// @brief �R���X�g���N�^
	/// @param useLocalPos �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	AbstractRenderer(bool useLocalPos);

	/// @brief �`��J�n����
	virtual void Begin(void) = 0;

	/// @brief �`�揈�� 
	virtual void Render(void) = 0;

	/// @brief �`��I������ 
	virtual void End(void) = 0;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) = 0;

	/// @brief �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩��Ԃ� 
	/// @return �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	bool UseLocalPos(void) const;

	/// @brief �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩���Z�b�g
	/// @param flag �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	void SetUseLocalPos(bool flag);

	/// @brief �`��Ώۂ̃I�u�W�F�N�g���폜���ꂽ����Ԃ� 
	/// @return �폜���ꂽ��
	virtual bool IsDeleted(void) const = 0;
protected:
	// ���̕`��p�X�N���[���̃n���h��ID(Begin()�ł����ɑޔ�����End()�Ō��ɖ߂�)
	int defaultScreenHadle_;

	// �`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	bool useLocalPos_;
};
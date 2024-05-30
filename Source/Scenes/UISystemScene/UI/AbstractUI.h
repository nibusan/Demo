#pragma once
#include <memory>
#include <functional>
#include "../../../Common/Vector2.h"
#include "../../../GameObject/GameObject2D.h"
#include "../../../GameObject/Transform.h"

class Graphic;
/// @brief UI�̒��ۃN���X�ł�
/// @note 2D��UI�Ŏg�����Ƃ�O��ɐ݌v���Ă���̂�3D�ł͓����܂���
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;


	/// @brief �����\�����邩���Z�b�g
	/// @param flag �����\�����邩�̃t���O
	void SetHighlighted(bool flag);

	/// @brief ����UI���N���b�N�ł��邩��Ԃ�
	/// @return �N���b�N�ł��邩
	[[nodiscard]] bool IsClickable(void) const;

	/// @brief ����UI���N���b�N�ł��邩���Z�b�g
	/// @param isClickable �N���b�N�ł��邩
	void SetClickable(bool isClickable);

	/// @brief �N���b�N���ꂽ���ɌĂяo�����R�[���o�b�N�֐����Z�b�g
	/// @param callBack �R�[���o�b�N�֐�
	void SetOnClickCallBack(const std::function<void(void)>& callBack);

protected:
	// �����\������Ă邩
	bool isHighlighted_;

	// ����UI�̓N���b�N�ł��邩
	bool isClickable_;

	// �N���b�N���ꂽ���ɌĂяo�����R�[���o�b�N�֐�(isClickable_��true�̎��̂ݎg�p�ł��܂�)
	std::function<void(void)> onClickCallBack_;

	// ����UI��`�悷�邽�߂̃X�N���[��
	//std::unique_ptr<Graphic> renderScreen_;

	void Init_GameObject2D(void) override;
	void Update_GameObject2D(void) override;
	void Release_GameObject2D(void) override;
	
	// �h���N���X�Œ�`
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;

	/// @brief �����\������Ă鎞�̍X�V���� 
	virtual void HighlightUpdate(void);

	/// @brief �N���b�N���ꂽ���ɌĂ΂��R�[���o�b�N�֐����Ăяo��
	void OnClick(void);
};


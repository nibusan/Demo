#pragma once
#include <memory>
#include "../../../Common/Vector2.h"
#include "../../../GameObject/GameObject2D.h"
#include "../../../GameObject/Transform.h"

/// @brief UI�̒��ۃN���X�ł�
/// @brief 2D��p�ł�
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	/// @brief �����\�����邩���Z�b�g
	/// @param flag �����\�����邩�̃t���O
	void SetHighlighted(bool flag);
protected:
	// �����\������Ă邩
	bool isHighlighted_;

	// �h���N���X�Œ�`
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;

	/// @brief �����\������Ă鎞�̍X�V���� 
	virtual void HighlightUpdate(void);
};


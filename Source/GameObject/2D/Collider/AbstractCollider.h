#pragma once
#include "../../../Common/Vector2.h"
#include "Collider_Info.h"

class AbstractCollider {
public:
	AbstractCollider(void);
	virtual ~AbstractCollider(void) = default;

	AbstractCollider(const Vector2<float>& centerPos);

	/// @brief �_�����̃R���C�_�[�̒��ɓ����Ă邩�𔻒�
	/// @param point �_�̍��W
	/// @return �Փ˂��Ă邩�ǂ���
	virtual bool IsContains(const Vector2<float>& point) const = 0;
protected:
	// ���S���W
	Vector2<float> centerPos_;

	// �R���C�_�[�̎��
	Collider_Info::TYPE type_;
};
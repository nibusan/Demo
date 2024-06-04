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

	/// @brief ���S���W��Ԃ� 
	/// @return ���W
	const Vector2<float>& GetCenterPos(void) const;

	/// @brief ���S���W���Z�b�g����
	/// @param pos ���W
	void SetCenterPos(const Vector2<float>& centerPos);
protected:
	// ���S���W
	Vector2<float> centerPos_;

	// �R���C�_�[�̎��
	Collider_Info::TYPE type_;
};
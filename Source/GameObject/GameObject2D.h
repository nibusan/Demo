#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "../Common/Vector2.h"

class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	virtual ~GameObject2D(void) override = default;

	/// @brief 2D�̃Q�[���I�u�W�F�N�g��Transform��Ԃ� 
	/// @return 2D��Transform
	[[nodiscard]] const Transform<Vector2<float>>& GetTransform(void) const;
	
	/// @brief Transform�ɓn���f�[�^���Z�b�g����
	/// @param pos ���W
	/// @param localPos ���[�J�����W
	/// @param rot �p�x
	/// @param localRot ���[�J���p�x(���O�ς���)
	/// @param scl �X�P�[���l
	/// @param localScl ���[�J���X�P�[���l(���O�ς���)
	void SetTransformData(
		const Vector2<float>& pos, 
		const Vector2<float>& localPos, 
		const Vector2<float>& rot, 
		const Vector2<float>& localRot, 
		const Vector2<float>& scl,
		const Vector2<float>& localScl
	);
protected:
	// �Q�[���I�u�W�F�N�g�̊�b�f�[�^
	Transform<Vector2<float>> transform_;

	virtual void Init_GameObject(void) = 0;
	virtual void Update_GameObject(void) = 0;
	virtual void Release_GameObject(void) = 0;
};

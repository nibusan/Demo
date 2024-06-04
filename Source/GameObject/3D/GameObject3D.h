#pragma once
#include "../GameObject.h"
#include "Transform3D.h"
#include "../../Common/Vector3.h"

class GameObject3D : public GameObject {
public:
	GameObject3D(void) = default;
	virtual ~GameObject3D(void) override = default;

	/// @brief �q�I�u�W�F�N�g��ǉ�����
	/// @param child �q�I�u�W�F�N�g
	void AddChild(std::shared_ptr<GameObject> child) override;

	/// @brief 3D�̃Q�[���I�u�W�F�N�g��Transform�̎Q�Ƃ�Ԃ� 
	/// @note �O�����璆�g��M�邱�Ƃ�����̂ł�����const���O���Ă܂�
	/// @return 3D��Transform
	[[nodiscard]] Transform3D& GetTransform(void);
	
	/// @brief Transform�ɓn���f�[�^���Z�b�g����
	/// @param localPos ���[�J�����W
	/// @param localRot ���[�J���p�x(���O�ς���)
	/// @param localScl ���[�J���X�P�[���l(���O�ς���)
	void SetTransformData( 
		const Vector3<float>& localPos, 
		const Vector3<float>& localRot, 
		const Vector3<float>& localScl
	);
protected:
	// �Q�[���I�u�W�F�N�g�̊�b�f�[�^
	Transform3D transform_;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	// �h���N���X�Œ�` 
	virtual void Init_GameObject3D(void) = 0;
	virtual void Update_GameObject3D(void) = 0;
	virtual void Release_GameObject3D(void) = 0;

	/// @brief �e�I�u�W�F�N�g���Z�b�g
	/// @param parent �e�I�u�W�F�N�g
	void SetParent(std::weak_ptr<GameObject> parent) override;
private:
	/// @brief �e�I�u�W�F�N�g���l�����Č��݂�Transform(3D)��current�̒l���v�Z����
	void CalculateTransform3D(void);

};
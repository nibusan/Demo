#pragma once
#include "../GameObject.h"
#include "Transform2D.h"
#include "../../Common/Vector2.h"
#include "../../GameObject/2D/Collider/Collider_Info.h"
#include "../../GameObject/2D/Collider/AbstractCollider.h"
#include "../../GameObject/2D/Collider/CircleCollider.h"
#include "../../GameObject/2D/Collider/RectCollider.h"

class AbstractCollider;
class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	virtual ~GameObject2D(void) override = default;

	/// @brief �q�I�u�W�F�N�g��ǉ�����
	/// @param child �q�I�u�W�F�N�g
	void AddChild(std::shared_ptr<GameObject> child) override;

	/// @brief 2D�̃Q�[���I�u�W�F�N�g��Transform�̎Q�Ƃ�Ԃ� 
	/// @note �O�����璆�g��M�邱�Ƃ�����̂ł�����const���O���Ă܂�
	/// @return 2D��Transform
	[[nodiscard]] Transform2D& GetTransform(void);
	
	/// @brief Transform�ɓn���f�[�^���Z�b�g����
	/// @param localPos ���[�J�����W
	/// @param localRot ���[�J���p�x(���O�ς���)
	/// @param localScl ���[�J���X�P�[���l(���O�ς���)
	void SetTransformData( 
		const Vector2<float>& localPos, 
		float localRot, 
		float localScl
	);

	/// @brief �R���C�_�[�𐶐�����
	/// @tparam T ��������R���C�_�[�̃N���X
	/// @tparam ...Args �R���C�_�[�ɗ^�������
	/// @param centerPos ���S���W
	/// @param ...args �R���C�_�[�ɗ^�������
	template <typename T, typename ...Args>
	void CreateCollider(const Vector2<float>& centerPos, Args&& ...args);

	std::weak_ptr<AbstractCollider> GetCollider(void) const;
protected:
	// �Q�[���I�u�W�F�N�g�̊�b�f�[�^
	Transform2D transform_;

	// �R���C�_�[
	std::shared_ptr<AbstractCollider> collider_;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	// �h���N���X�Œ�` 
	virtual void Init_GameObject2D(void) = 0;
	virtual void Update_GameObject2D(void) = 0;
	virtual void Release_GameObject2D(void) = 0;

	/// @brief �e�I�u�W�F�N�g���Z�b�g
	/// @param parent �e�I�u�W�F�N�g
	void SetParent(std::weak_ptr<GameObject> parent) override;
private:
	/// @brief �e�I�u�W�F�N�g���l�����Č��݂�Transform(2D)��current�̒l���v�Z����
	void CalculateTransform2D(void);

};

template<typename T, typename ...Args>
inline void GameObject2D::CreateCollider(const Vector2<float>& centerPos, Args && ...args) {
	collider_ = std::make_shared<T>(centerPos, std::forward<Args>(args)...);
}

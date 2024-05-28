#pragma once
#include <memory>
#include <vector>
#include "Transform.h"

/// @brief �Q�[���I�u�W�F�N�g�̊��N���X
/// @brief (Unity���Q�l�ɂ��Đ݌v���܂���)
class GameObject : public std::enable_shared_from_this<GameObject> {
public:
	GameObject(void);
	virtual ~GameObject(void) = default;
 
	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief ���̃Q�[���I�u�W�F�N�g���A�N�e�B�u����Ԃ�
	/// @return �A�N�e�B�u���ǂ���
	[[nodiscard]] bool IsActive(void) const;

	/// @brief ���̃Q�[���I�u�W�F�N�g���A�N�e�B�u�����Z�b�g
	/// @param flag �A�N�e�B�u���ǂ���
	void SetActive(bool flag);

	/// @brief �e�I�u�W�F�N�g��Ԃ� 
	/// @return �e�I�u�W�F�N�g
	[[nodiscard]] const std::weak_ptr<GameObject>& GetParent(void) const;
	
	/// @brief �e�I�u�W�F�N�g���Z�b�g
	/// @param parent �e�I�u�W�F�N�g
	void SetParent(const std::shared_ptr<GameObject>& parent);

	/// @brief �q�I�u�W�F�N�g���i�[�����z���Ԃ� 
	/// @return �q�I�u�W�F�N�g���i�[�����z��
	[[nodiscard]] const std::vector<std::shared_ptr<GameObject>> GetChilds(void) const;
	
	/// @brief �q�I�u�W�F�N�g��ǉ�����
	/// @param child �q�I�u�W�F�N�g
	void AddChild(const std::shared_ptr<GameObject>& child);

protected:
	// �A�N�e�B�u���ǂ���
	bool isActive_;

	// �e�I�u�W�F�N�g
	std::weak_ptr<GameObject> parent_;
	
	// �q�I�u�W�F�N�g���i�[�����ϒ��z��
	std::vector<std::shared_ptr<GameObject>> childs_;

	// �h���N���X�Œ�`����֐�
	virtual void Init_GameObject(void) = 0;
	virtual void Update_GameObject(void) = 0;
	virtual void Release_GameObject(void) = 0;
};

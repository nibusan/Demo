#pragma once
#include "SceneType.h"

/// @brief �V�[���̒��ۃN���X
class AbstractScene {
public:
	AbstractScene(void);
	virtual ~AbstractScene(void) = default;

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Release(void) = 0;

	/// @brief ���̃V�[���̎�ނ�Ԃ�
	/// @return �V�[���̎��
	Scene::TYPE GetType(void) const;
private:

protected:
	// ���̃V�[���̎��
	Scene::TYPE type_;

};
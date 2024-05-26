#pragma once
#include "SceneType.h"

/// @brief �V�[���̊��N���X
class AbstractScene {
public:
	AbstractScene(void);
	virtual ~AbstractScene(void) = default;

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Release(void) = 0;
private:

protected:
	// ���̃V�[���̎��
	Scene::TYPE type_;

	/// @brief ���̃V�[���̎�ނ�Ԃ�
	/// @return �V�[���̎��
	Scene::TYPE GetType(void) const;
};
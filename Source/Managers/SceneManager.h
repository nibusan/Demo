#pragma once
#include <memory>
#include "../Common/StaticSingleton.h"
#include "../Scenes/SceneType.h"
#include "../Scenes/AbstractScene.h"

class SceneManager : public StaticSingleton<SceneManager> {
public:
	~SceneManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(SceneManager);

	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief ���݂̃V�[���̎�ނ�Ԃ� 
	/// @return ���݂̃V�[���̎��
	Scene::TYPE GetCurrentSceneType(void);

	/// @brief ���̃t���[���Ő؂�ւ���V�[�����Z�b�g
	/// @param type �V�[���̎��
	void SetNextScene(Scene::TYPE type);
private:
	// ���݂̃V�[���̃C���X�^���X
	std::unique_ptr<AbstractScene> currentScene_;
	
	// ���̃V�[���̎�ނ��i�[
	Scene::TYPE nextSceneType_;

	SceneManager();

	/// @brief �V�[����؂�ւ���
	/// @param �V�[���̎��
	void ChangeScene(Scene::TYPE type);
};
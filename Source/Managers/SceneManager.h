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
	void Draw(void);
	void Release(void);

	/// @brief �V�[����؂�ւ���
	/// @param �V�[���̎��
	void ChangeScene(Scene::TYPE type);

	/// @brief ���݂̃V�[���̎�ނ�Ԃ� 
	/// @return ���݂̃V�[���̎��
	Scene::TYPE GetCurrentSceneType(void);

private:
	// ���݂̃V�[���̃C���X�^���X
	std::unique_ptr<AbstractScene> currentScene_;

	SceneManager() = default;

};
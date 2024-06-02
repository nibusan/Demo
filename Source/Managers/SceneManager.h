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

	/// @brief シーンを切り替える
	/// @param シーンの種類
	void ChangeScene(Scene::TYPE type);

	/// @brief 現在のシーンの種類を返す 
	/// @return 現在のシーンの種類
	Scene::TYPE GetCurrentSceneType(void);

private:
	// 現在のシーンのインスタンス
	std::unique_ptr<AbstractScene> currentScene_;

	SceneManager() = default;

};
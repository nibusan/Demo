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

	/// @brief 現在のシーンの種類を返す 
	/// @return 現在のシーンの種類
	Scene::TYPE GetCurrentSceneType(void);

	/// @brief 次のフレームで切り替えるシーンをセット
	/// @param type シーンの種類
	void SetNextScene(Scene::TYPE type);
private:
	// 現在のシーンのインスタンス
	std::unique_ptr<AbstractScene> currentScene_;
	
	// 次のシーンの種類を格納
	Scene::TYPE nextSceneType_;

	SceneManager();

	/// @brief シーンを切り替える
	/// @param シーンの種類
	void ChangeScene(Scene::TYPE type);
};
#pragma once
#include <memory>
#include "../Common/StaticSingleton.h"

class AbstractScene;
class SceneManager : StaticSingleton<SceneManager> {
public:
	~SceneManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(SceneManager);
private:
	// 現在のシーンのインスタンス
	std::unique_ptr<AbstractScene> currentScene_;

	SceneManager() = default;

	void Init(void);
	void Update(void);
	void Draw(void);
	void Release(void);
};


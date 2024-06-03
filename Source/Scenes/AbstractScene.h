#pragma once
#include "SceneType.h"

/// @brief シーンの抽象クラス
class AbstractScene {
public:
	AbstractScene(void);
	virtual ~AbstractScene(void) = default;

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Release(void) = 0;

	/// @brief このシーンの種類を返す
	/// @return シーンの種類
	Scene::TYPE GetType(void) const;
private:

protected:
	// このシーンの種類
	Scene::TYPE type_;

};
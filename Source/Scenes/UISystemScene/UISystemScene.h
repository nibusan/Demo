#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level] UIÇÃèàóù
class GameObject;
class AbstractUI;
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
private:
	std::shared_ptr<GameObject> obj1_;

};


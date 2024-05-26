#pragma once
#include <memory>
#include "../AbstractScene.h"

class GameObject;
/// @brief [Unknown Level] UIÇÃèàóù
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
private:
	std::unique_ptr<GameObject> obj1_;
	std::unique_ptr<GameObject> obj2_;

};


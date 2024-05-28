#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level] UIÇÃèàóù
class GameObject;
class AbstractUI;
class UI_ButtonRenderer;
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
	std::shared_ptr<AbstractUI> ui1_;
	std::shared_ptr<AbstractUI> ui2_;
	std::shared_ptr<AbstractUI> ui3_;
	std::shared_ptr<UI_ButtonRenderer> uiRenderer_;

};


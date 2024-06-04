#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UI�̏���(���ǔ�)
class UILayer;
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;
private:
	std::unique_ptr<UILayer> uiLayer_;
};


#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UI�̏���(���ǔ�)
class Camera;
class UILayer;
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;
private:
	std::shared_ptr<Camera> camera_;
	std::unique_ptr<UILayer> uiLayer_;
};


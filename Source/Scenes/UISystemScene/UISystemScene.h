#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UI�̏���(���ǔ�)
class Camera;
class UILayer;
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	virtual ~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;
private:
	// ���C���J����(����͎g�p���Ă܂���)
	std::shared_ptr<Camera> camera_;

	// ���̃V�[���̃x�[�X�ƂȂ�UI�̃��C���[
	std::unique_ptr<UILayer> uiLayer_;
};


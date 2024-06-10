#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UIの処理(改良版)
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
	// メインカメラ(今回は使用してません)
	std::shared_ptr<Camera> camera_;

	// このシーンのベースとなるUIのレイヤー
	std::unique_ptr<UILayer> uiLayer_;
};


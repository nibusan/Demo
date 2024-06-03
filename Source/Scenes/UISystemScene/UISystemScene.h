#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UI‚Ìˆ—(‰ü—Ç”Å)
class GameObject;
class AbstractUI;
class AbstractRenderer;
class Graphic;
class Font;
class UISystemScene : public AbstractScene {
public:
	UISystemScene();
	~UISystemScene() override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;
private:
	std::shared_ptr<AbstractUI> uiImage_;
	std::shared_ptr<AbstractRenderer> uiImageRenderer_;
	std::weak_ptr<Graphic> graphic_;
	std::shared_ptr<Font> font_;
};


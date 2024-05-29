#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UI‚Ìˆ—(‰ü—Ç”Å)
class GameObject;
class AbstractUI;
class UI_ImageRenderer;
class UI_TextRenderer;
class UI_ButtonRenderer;
class Graphic;
class Font;
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
	std::shared_ptr<UI_ImageRenderer> uiImageRenderer_;
	std::shared_ptr<UI_TextRenderer> uiTextRenderer_;
	std::shared_ptr<UI_ButtonRenderer> uiButtonRenderer_;
	std::shared_ptr<Graphic> graphic_;
	std::shared_ptr<Font> font_;
};


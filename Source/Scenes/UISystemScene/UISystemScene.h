#pragma once
#include <memory>
#include "../AbstractScene.h"

/// @brief [Unknown Level & Detonation] UIÇÃèàóù(â¸ó«î≈)
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
	std::shared_ptr<AbstractUI> uiButton_;
	std::shared_ptr<AbstractUI> uiButton2_;
	std::shared_ptr<AbstractUI> uiButton3_;
	std::shared_ptr<UI_ButtonRenderer> uiButtonRenderer_;
	std::shared_ptr<UI_ButtonRenderer> uiButtonRenderer2_;
	std::shared_ptr<UI_ButtonRenderer> uiButtonRenderer3_;
	std::weak_ptr<Graphic> graphic_;
	std::shared_ptr<Font> font_;
};


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
	void Draw(void) override;
	void Release(void) override;
private:
	std::shared_ptr<GameObject> obj1_;
	std::shared_ptr<AbstractUI> uiButton_;
	std::shared_ptr<AbstractUI> uiButton2_;
	std::shared_ptr<AbstractUI> uiButton3_;
	std::shared_ptr<AbstractRenderer> uiButtonRenderer_;
	std::shared_ptr<AbstractRenderer> uiButtonRenderer2_;
	std::shared_ptr<AbstractRenderer> uiButtonRenderer3_;
	std::shared_ptr<AbstractUI> uiImage_;
	std::shared_ptr<AbstractUI> uiImage2_;
	std::shared_ptr<AbstractUI> uiText_;
	std::shared_ptr<AbstractUI> uiText2_;
	std::shared_ptr<AbstractRenderer> uiImageRenderer_;
	std::shared_ptr<AbstractRenderer> uiImageRenderer2_;
	std::shared_ptr<AbstractRenderer> uiTextRenderer_;
	std::shared_ptr<AbstractRenderer> uiTextRenderer2_;
	std::weak_ptr<Graphic> graphic_;
	std::shared_ptr<Font> font_;
	std::shared_ptr<AbstractUI> uiSystemMenu_;
	std::shared_ptr<AbstractRenderer> uiSystemMenuRenderer_;
};


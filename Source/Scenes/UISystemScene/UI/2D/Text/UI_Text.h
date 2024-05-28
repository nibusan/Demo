#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �e�L�X�g��UI�̃N���X�ł�
class Font;
class UI_Text : public AbstractUI {
public:
	UI_Text(void) = default;
	~UI_Text(void) = default;

	UI_Text(std::shared_ptr<Font> font, const std::string& text);

	std::weak_ptr<Font> GetFont(void) const;
	std::string GetText(void) const;
private:
	// �g�p����t�H���g
	std::shared_ptr<Font> font_;

	// �`�悷��e�L�X�g
	std::string text_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


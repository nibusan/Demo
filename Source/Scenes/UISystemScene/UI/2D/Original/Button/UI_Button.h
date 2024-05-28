#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

/// @brief �e�L�X�g��UI�̃N���X�ł�
class UI_Image;
class UI_Text;
class UI_Button : public AbstractUI {
public:
	UI_Button(void) = default;
	~UI_Button(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	/// @param uiText �x�[�X�ƂȂ�e�L�X�g��UI
	UI_Button(const std::shared_ptr<UI_Image>& uiImage, const std::shared_ptr<UI_Text>& uiText);

	std::weak_ptr<UI_Image> GetUIImage(void);
	std::weak_ptr<UI_Text> GetUIText(void);
private:
	// �g�p����t�H���g
	std::shared_ptr<UI_Image> uiImage_;
	std::shared_ptr<UI_Text> uiText_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


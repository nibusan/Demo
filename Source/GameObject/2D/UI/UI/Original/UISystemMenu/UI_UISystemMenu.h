#pragma once
#include <array>
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �e�L�X�g��UI�̃N���X�ł�
class UI_Image;
class UI_Text;
class UI_Button;
class UI_UISystemMenu : public AbstractUI {
public:
	static constexpr int BUTTON_COUNT = 4;

	UI_UISystemMenu(void);
	~UI_UISystemMenu(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	/// @param uiText �x�[�X�ƂȂ�e�L�X�g��UI
	UI_UISystemMenu(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		const std::shared_ptr<UI_Image>& backGround, 
		const std::shared_ptr<UI_Text>& title,
		const std::shared_ptr<UI_Button>& button1,
		const std::shared_ptr<UI_Button>& button2,
		const std::shared_ptr<UI_Button>& button3,
		const std::shared_ptr<UI_Button>& button4
	);

	/// @brief �w�i�摜������UI��Ԃ� 
	/// @return �w�i�摜������UI
	std::weak_ptr<UI_Image> GetUIImage(void);

	/// @brief �^�C�g��������UI��Ԃ� 
	/// @return �^�C�g��������UI
	std::weak_ptr<UI_Text> GetUIText(void);

	/// @brief �e�L�X�g������UI��Ԃ�
	/// @return �e�L�X�g������UI
	[[nodiscard]] const std::array<std::shared_ptr<UI_Button>, BUTTON_COUNT>& GetUIButtons(void);
private:
	// �w�i�摜������UI
	std::shared_ptr<UI_Image> uiImage_BackGround_;

	// ���j���[�̃^�C�g��
	std::shared_ptr<UI_Text> uiText_Title_;

	// �{�^��������UI
	std::array<std::shared_ptr<UI_Button>, BUTTON_COUNT> buttonList_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};


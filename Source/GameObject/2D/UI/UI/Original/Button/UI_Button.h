#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �{�^��UI�̃N���X�ł�
class UI_Image;
class UI_Text;
class UI_Button : public AbstractUI {
public:
	UI_Button(void);
	~UI_Button(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	/// @param uiText �x�[�X�ƂȂ�e�L�X�g��UI
	UI_Button(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType, 
		const std::shared_ptr<UI_Image>& uiImage, 
		const std::shared_ptr<UI_Text>& uiText
	);

	/// @brief �w�i�摜������UI��Ԃ� 
	/// @return �w�i�摜������UI
	std::weak_ptr<UI_Image> GetUIImage(void);
	
	/// @brief �e�L�X�g������UI��Ԃ�
	/// @return �e�L�X�g������UI
	std::weak_ptr<UI_Text> GetUIText(void);
private:
	// �w�i�摜������UI
	std::shared_ptr<UI_Image> uiImage_;

	// �e�L�X�g������UI
	std::shared_ptr<UI_Text> uiText_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UI�𒷉������Ă��鎞�̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickDown(void) override;

	/// @brief UI�𗣂������̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickUp(void) override;
};


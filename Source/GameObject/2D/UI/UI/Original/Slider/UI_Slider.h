#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �X���C�_�[UI�̃N���X�ł�
class UI_Image;
class UI_Slider : public AbstractUI {
public:
	UI_Slider(void);
	virtual ~UI_Slider(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	/// @param uiText �x�[�X�ƂȂ�e�L�X�g��UI
	UI_Slider(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		const std::shared_ptr<UI_Image>& uiImage_BaseImage,
		const std::shared_ptr<UI_Image>& uiImage_CircleImage,
		const std::shared_ptr<UI_Image>& uiImage_GaugeImage,
		float min,
		float max
	);

	/// @brief �w�i�摜������UI��Ԃ� 
	/// @return �w�i�摜������UI
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_BaseImage(void);
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_CircleImage(void);
	[[nodiscard]] std::weak_ptr<UI_Image> GetUIImage_GaugeImage(void);

	/// @brief �X���C�_�[���Ǘ�����l�̍ŏ��l��Ԃ�
	/// @return �ŏ��l
	float GetMinValue(void) const;
	
	/// @brief �X���C�_�[���Ǘ�����l�̍ő�l��Ԃ�
	/// @return �ő�l
	float GetMaxValue(void) const;

	/// @brief �X���C�_�[���Ǘ����錻�݂̒l��Ԃ� 
	/// @return ���݂̒l
	float GetCurrentValue(void) const;
private:
	// �w�i�摜������UI
	std::shared_ptr<UI_Image> uiImage_BaseImage_;
	std::shared_ptr<UI_Image> uiImage_CircleImage_;
	std::shared_ptr<UI_Image> uiImage_GaugeImage_;

	// �X���C�_�[�������l�̍ŏ��l
	float min_;

	// �X���C�_�[�������l�̍ő�l
	float max_;

	// �X���C�_�[�̌��݂̒l
	float currentValue_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UI�𒷉������Ă��鎞�̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickDown(void) override;
};


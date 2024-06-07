#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �A�C�e��UI�̃N���X�ł�
class Item;
class UI_Item : public AbstractUI {
public:
	UI_Item(void) = default;
	virtual ~UI_Item(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	UI_Item(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		std::weak_ptr<Graphic> image,
		std::weak_ptr<Item> item
	);

	/// @brief �Q�ƌ��̃A�C�e����Ԃ� 
	/// @return �A�C�e��
	std::weak_ptr<Item> GetItem(void);

	/// @brief �A�C�e���̉摜��Ԃ� 
	/// @return �A�C�e���̉摜
	std::weak_ptr<Graphic> GetItemImage(void);
private:
	// �`�悷��A�C�e��
	std::weak_ptr<Item> item_;

	// �`�悷��摜
	std::weak_ptr<Graphic> image_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;
};
#pragma once
#include <memory>
#include <string>
#include "../../AbstractUI.h"

/// @brief �C���x���g��UI�̃N���X�ł�
class UI_Image;
template <typename T>
class Inventory;
class Item;
class UI_Inventory : public AbstractUI {
public:
	UI_Inventory(void);
	~UI_Inventory(void) = default;

	/// @brief �R���X�g���N�^
	/// @param uiImage �x�[�X�ƂȂ�摜��UI
	UI_Inventory(
		const Vector2<float> canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID, 
		std::shared_ptr<Inventory<Item>> inventory,
		const std::shared_ptr<UI_Image>& uiImage
	);

	/// @brief �Q�ƌ��̃C���x���g����Ԃ� 
	/// @return �C���x���g��
	std::weak_ptr<Inventory<Item>> GetInventory(void);

	/// @brief �w�i�摜������UI��Ԃ� 
	/// @return �w�i�摜������UI
	std::weak_ptr<UI_Image> GetUIImage(void);

private:
	// �Q�ƌ��̃C���x���g��
	std::shared_ptr<Inventory<Item>> inventory_;

	// �w�i�摜������UI
	std::shared_ptr<UI_Image> uiImage_;

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	/// @brief UI�𒷉������Ă��鎞�̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickDown(void) override;

	/// @brief UI�𗣂������̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickUp(void) override;
};


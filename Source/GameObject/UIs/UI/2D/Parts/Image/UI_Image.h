#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

class Graphic;
class UI_Image : public AbstractUI {
public:
	UI_Image(void);
	~UI_Image(void) = default;

	/// @brief �R���X�g���N�^
	/// @param canvasSize UI�̃L�����o�X�̃T�C�Y
	/// @param image �`�悷��摜
	UI_Image(
		const Vector2<float>& canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		std::weak_ptr<Graphic> image
	);

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	std::weak_ptr<Graphic> GetImage(void);
private:
	// �`�悷��摜
	std::weak_ptr<Graphic> image_;

	/// @brief �����\������Ă鎞�̍X�V���� 
	void HighlightUpdate(void) override;
};


#pragma once
#include <memory>
#include <string>
#include "../../../AbstractUI.h"

class Graphic;
class UI_Image : public AbstractUI {
public:
	UI_Image(void) = default;
	~UI_Image(void) = default;

	/// @brief �R���X�g���N�^
	/// @param image �`�悷��摜
	UI_Image(std::shared_ptr<Graphic> image);

	void Init_UI(void) override;
	void Update_UI(void) override;
	void Release_UI(void) override;

	std::weak_ptr<Graphic> GetImage(void);
private:
	// �`�悷��摜
	std::shared_ptr<Graphic> image_;

	/// @brief �����\������Ă鎞�̍X�V���� 
	void HighlightUpdate(void) override;
};


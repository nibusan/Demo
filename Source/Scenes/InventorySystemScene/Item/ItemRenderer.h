#pragma once
#include <memory>
#include "../../../Renderer/AbstractRenderer.h"

/// @brief �A�C�e����`�悷�邽�߂̃N���X
class Item;
class Graphic;
class ItemRenderer : public AbstractRenderer {
public:
	ItemRenderer(void) = default;
	~ItemRenderer(void) override = default;

	/// @brief �R���X�g���N�^
	/// @param inventory �`�悷��C���x���g��
	ItemRenderer(std::shared_ptr<Item> item);

	/// @brief �`��J�n����
	virtual void Begin(void) override;

	/// @brief �`�揈�� 
	virtual void Render(void) override;

	/// @brief �`��I������ 
	virtual void End(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �`�悷��A�C�e��
	std::shared_ptr<Item> item_;

	// �`�悷��A�C�e���ɕR�Â����摜
	std::unique_ptr<Graphic> image_;
};
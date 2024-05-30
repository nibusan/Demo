#pragma once
#include <memory>
#include <DxLib.h>
#include "../../../Renderer/IRenderer.h"

/// @brief �C���x���g����`�悷�邽�߂̃N���X
/// @brief �����Item�N���X���g�p����O��Ő݌v���Ă܂�
template <typename T>
class Inventory;
class Item;
class InventoryRenderer : public IRenderer {
public:
	InventoryRenderer(void) = default;
	~InventoryRenderer(void) override = default;
	
	/// @brief �R���X�g���N�^
	/// @param inventory �`�悷��C���x���g��
	InventoryRenderer(std::shared_ptr<Inventory<Item>> inventory);

	/// @brief �`�揈��  
	void Render(void) override;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) override;
private:
	// �C���x���g���̃f�[�^
	std::shared_ptr<Inventory<Item>> inventory_;
};
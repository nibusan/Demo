#pragma once
#include <memory>
#include "../AbstractScene.h"

class Inventory;

/// @brief [Unknown Level] �v���C���[�̃C���x���g���̏���
class InventorySystemScene : public AbstractScene {
public:
	InventorySystemScene(void);
	~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;

private:
	std::unique_ptr<Inventory> inventory_;

};


#pragma once
#include <memory>
#include "../AbstractScene.h"

template <typename T>
class Inventory;
class UI_Inventory;
class UI_InventoryRenderer;
class Item;
class UILayer;
/// @brief [Unknown Level] �v���C���[�̃C���x���g���̏���
class InventorySystemScene : public AbstractScene {
public:
	InventorySystemScene(void);
	~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;

private:
	std::unique_ptr<UILayer> uiLayer_;

	std::shared_ptr<Inventory<Item>> inventory_;
	std::shared_ptr<UI_Inventory> uiInventory_;
	std::unique_ptr<UI_InventoryRenderer> inventoryRenderer_;

	// �ǉ�����A�C�e�����i�[(ImGui�p)
	int addItemID_;
	std::unique_ptr<Item> addItem_;
};
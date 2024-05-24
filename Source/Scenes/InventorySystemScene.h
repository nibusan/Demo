#pragma once
#include "AbstractScene.h"

class InventorySystemScene : AbstractScene {
	InventorySystemScene(void);
	~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
};


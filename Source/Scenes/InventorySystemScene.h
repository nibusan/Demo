#pragma once
#include "AbstractScene.h"

/// @brief [Unknown Level] プレイヤーのインベントリの処理
class InventorySystemScene : public AbstractScene {
public:
	InventorySystemScene(void);
	~InventorySystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;

private:

};


#include <DxLib.h>
#include "InventorySystemScene.h"
#include "SceneType.h"

InventorySystemScene::InventorySystemScene(void) {
	// ���̃V�[���̎�ނ��Z�b�g
	type_ = SCENE_TYPE::INVENTORY_SYSTEM;
}

void InventorySystemScene::Init(void) {

}

void InventorySystemScene::Update(void) {

}

void InventorySystemScene::Draw(void) {
	DrawBox(0, 0, 200, 200, 0x00FF00, true);
}

void InventorySystemScene::Release(void) {

}

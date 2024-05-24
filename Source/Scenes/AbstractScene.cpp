#include "AbstractScene.h"

AbstractScene::AbstractScene(void) : type_(SCENE_TYPE::NONE) {}

SCENE_TYPE AbstractScene::GetType(void) {
	return type_;
}

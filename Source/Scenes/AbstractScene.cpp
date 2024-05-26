#include "AbstractScene.h"

AbstractScene::AbstractScene(void) : 
type_(Scene::TYPE::NONE) {}

Scene::TYPE AbstractScene::GetType(void) const {
	return type_;
}

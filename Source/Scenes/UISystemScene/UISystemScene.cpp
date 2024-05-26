#include "UISystemScene.h"
#include "GameObject/GameObject2D.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	obj1_ = std::make_unique<GameObject2D>(Vector2<float>(500,600), Vector2<float>(0,0), Vector2<float>(1,1));
	obj1_->Init();
	obj2_ = std::make_unique<GameObject2D>(Vector2<float>(200,200), Vector2<float>(0,0), Vector2<float>(1,1));
	obj2_->Init();
}

void UISystemScene::Update(void) {
	obj1_->Update();
	obj2_->Update();
}

void UISystemScene::Draw(void) {
	obj1_->Draw();
	obj2_->Draw();
}

void UISystemScene::Release(void) {
	obj1_->Release();
	obj2_->Release();
}

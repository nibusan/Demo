#include <numbers>
#include "UISystemScene.h"
#include "../../GameObject/2D/GameObject2D.h"
#include "../../GameObject/2D/UI/UI/AbstractUI.h"
#include "../../GameObject/2D/UI/UI/Parts/Image/UI_Image.h"
#include "../../GameObject/2D/UI/UI/Parts/Image/UI_ImageRenderer.h"
#include "../../GameObject/2D/UI/UI/Parts/Text/UI_Text.h"
#include "../../GameObject/2D/UI/UI/Parts/Text/UI_TextRenderer.h"
#include "../../GameObject/2D/UI/UI/Original/Button/UI_Button.h"
#include "../../GameObject/2D/UI/UI/Original/Button/UI_ButtonRenderer.h"
#include "../../GameObject/2D/UI/UI/Original/UISystemMenu/UI_UISystemMenu.h"
#include "../../GameObject/2D/UI/UI/Original/UISystemMenu/UI_UISystemMenuRenderer.h"
#include "../../Common/Handle/Graphic/Graphic.h"
#include "../../Common/Handle/Font/Font.h"
#include "../../Managers/ResourceManager.h"
#include "../../Managers/RenderManager.h"
#include "../../Managers/InputManager.h"

UISystemScene::UISystemScene(void) {
	// このシーンの種類をセット
	type_ = Scene::TYPE::UI_SYSTEM;
}

void UISystemScene::Init(void) {
	// リソースファイル取得用
	auto& resourceManager = ResourceManager::GetInstance();

	graphic_ = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_IMAGE_TEST").lock());
	std::weak_ptr<Font> aFont = std::dynamic_pointer_cast<Font>(resourceManager.GetResourceFile("FONT_REVAMPED").lock());
	font_ = std::make_shared<Font>(
		aFont.lock()->GetFontName(),
		32
	);

	uiImage_ = std::make_shared<UI_Image>(
		graphic_.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT,
		graphic_
	);
	uiImage_->Init();
	uiImage_->SetTransformData(
		{ 20.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiImageRenderer_ = std::make_shared<UI_ImageRenderer>(false, std::dynamic_pointer_cast<UI_Image>(uiImage_));
	RenderManager::GetInstance().AddRenderer2D(uiImageRenderer_);
}

void UISystemScene::Update(void) {
	
	if(CheckHitKey(KEY_INPUT_W)) uiImage_->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_A)) uiImage_->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_S)) uiImage_->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_D)) uiImage_->GetTransform().localPos_.x++;

	uiImage_->Update();
}

void UISystemScene::Release(void) {
	//uiButton_->Release();
	//uiButton2_->Release();
	//uiButton3_->Release();
}

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
#include "../../Common/Handle/Graphic/Graphic.h"
#include "../../Common/Handle/Font/Font.h"
#include "../../Managers/ResourceManager.h"
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
		UI::UI_ORIGIN_TYPE::CENTER_CENTER,
		false,
		graphic_
	);

	uiImage2_ = std::make_shared<UI_Image>(
		graphic_.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::CENTER_CENTER,
		false,
		graphic_
	);

	uiImage_->AddChild(uiImage2_);


	Weak_Graphic buttonGraphic = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_BUTTON").lock());
	uiButton_ = std::make_shared<UI_Button>(
		Vector2<float>(800.0f,800.0f),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		true,
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
				static_cast<float>(GetDrawStringWidthToHandle("Button", 6, font_->GetHandle())),
				static_cast<float>(font_->GetFontSize())
			}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			font_, 
			"Button", 
			0xFFFFFF
		)
	);
	uiButton_->Init();
	uiButton_->SetTransformData(
		{ 650.0f, 467.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiButton2_ = std::make_shared<UI_Button>(
		Vector2<float>(800.0f,800.0f),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		true,
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button2", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			font_, 
			"Button2", 
			0xFFFFFF
		)
	);
	uiButton2_->Init();
	uiButton_->AddChild(uiButton2_);
	uiButton2_->SetTransformData(
		{ 20.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiButton3_ = std::make_shared<UI_Button>(
		Vector2<float>(800.0f,800.0f),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		true,
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			true,
			font_, 
			"Button3", 
			0xFFFFFF
		)
	);
	uiButton3_->Init();
	uiButton2_->AddChild(uiButton3_);
	uiButton3_->SetTransformData(
		{ 20.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiButtonRenderer_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(uiButton_));
	uiButtonRenderer2_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(uiButton2_));
	uiButtonRenderer3_ = std::make_shared<UI_ButtonRenderer>(std::dynamic_pointer_cast<UI_Button>(uiButton3_));
}

void UISystemScene::Update(void) {
	
	if(CheckHitKey(KEY_INPUT_W)) uiButton_->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_A)) uiButton_->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_S)) uiButton_->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_D)) uiButton_->GetTransform().localPos_.x++;

	if (CheckHitKey(KEY_INPUT_Q)) {
		uiButton2_->DeleteKankei();
	}

	if (InputManager::GetInstance().IsTrgDown(KEY_INPUT_E)) {
		uiButton_->AddChild(uiButton2_);
	}
	
	auto child = std::dynamic_pointer_cast<GameObject2D>(uiButton_->GetChilds()[0]->GetChilds()[0]);
	if(CheckHitKey(KEY_INPUT_UP)) child->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_LEFT)) child->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_DOWN)) child->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_RIGHT)) child->GetTransform().localPos_.x++;

	uiButton_->Update();
}

void UISystemScene::Draw(void) {
	/*uiButtonRenderer_->Begin();
	uiButtonRenderer_->Render();

	uiButtonRenderer2_->Begin();
	uiButtonRenderer2_->Render();
	
	uiButtonRenderer3_->Begin();
	uiButtonRenderer3_->Render();
	uiButtonRenderer3_->End();
	uiButtonRenderer2_->End();
	uiButtonRenderer_->End();*/

	uiButtonRenderer_->Begin();
	uiButtonRenderer_->Render();
	uiButtonRenderer_->End();

	if (uiButtonRenderer2_ != nullptr) {
		uiButtonRenderer2_->Begin();
		uiButtonRenderer2_->Render();
		uiButtonRenderer2_->End();
	}

	uiButtonRenderer3_->Begin();
	uiButtonRenderer3_->Render();
	uiButtonRenderer3_->End();
}

void UISystemScene::Release(void) {
	uiButton_->Release();
	uiButton2_->Release();
	uiButton3_->Release();
}

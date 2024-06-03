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

	uiImage2_ = std::make_shared<UI_Image>(
		graphic_.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT,
		graphic_
	);
	uiImage2_->Init();
	uiImage_->AddChild(uiImage2_);
	uiImage2_->SetTransformData(
		{ 100.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiText_ = std::make_shared<UI_Text>(
		Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Parent", 6, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
		UI::UI_ORIGIN_TYPE::UP_LEFT,
		font_, 
		"Parent", 
		0xFFFFFF
	);
	uiText_->Init();
	uiText_->SetTransformData(
		{ 800.0f, 20.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiText2_ = std::make_shared<UI_Text>(
		Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Child", 5, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
		UI::UI_ORIGIN_TYPE::UP_LEFT,
		font_, 
		"Child", 
		0xFFFFFF
	);
	uiText2_->Init();
	uiText_->AddChild(uiText2_);
	uiText2_->SetTransformData(
		{ 100.0f, 50.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);



	Weak_Graphic buttonGraphic = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_BUTTON").lock());
	uiButton_ = std::make_shared<UI_Button>(
		buttonGraphic.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
				static_cast<float>(GetDrawStringWidthToHandle("Button", 6, font_->GetHandle())),
				static_cast<float>(font_->GetFontSize())
			}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
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
		buttonGraphic.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button2", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			font_, 
			"Button2", 
			0xFFFFFF
		)
	);
	uiButton2_->Init();
	uiButton_->AddChild(uiButton2_);
	uiButton2_->SetTransformData(
		{ 50.0f, 50.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiButton3_ = std::make_shared<UI_Button>(
		buttonGraphic.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		std::make_shared<UI_Image>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			buttonGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			font_, 
			"Button3", 
			0xFFFFFF
		)
	);
	uiButton3_->Init();
	uiButton2_->AddChild(uiButton3_);
	uiButton3_->SetTransformData(
		{ 50.0f, 50.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiButtonRenderer_ = std::make_shared<UI_ButtonRenderer>(false, std::dynamic_pointer_cast<UI_Button>(uiButton_));
	uiButtonRenderer2_ = std::make_shared<UI_ButtonRenderer>(false, std::dynamic_pointer_cast<UI_Button>(uiButton2_));
	uiButtonRenderer3_ = std::make_shared<UI_ButtonRenderer>(false, std::dynamic_pointer_cast<UI_Button>(uiButton3_));

	uiImageRenderer_ = std::make_shared<UI_ImageRenderer>(false, std::dynamic_pointer_cast<UI_Image>(uiImage_));
	uiImageRenderer2_ = std::make_shared<UI_ImageRenderer>(false, std::dynamic_pointer_cast<UI_Image>(uiImage2_));

	uiTextRenderer_ = std::make_shared<UI_TextRenderer>(false, std::dynamic_pointer_cast<UI_Text>(uiText_));
	uiTextRenderer2_ = std::make_shared<UI_TextRenderer>(false, std::dynamic_pointer_cast<UI_Text>(uiText2_));

	Weak_Graphic menuGraphic = std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile("IMAGE_UI_UISYSTEMMENU").lock());
	uiSystemMenu_ = std::make_shared<UI_UISystemMenu>(
		menuGraphic.lock()->GetSize().ToVector2f(),
		UI::UI_ORIGIN_TYPE::UP_LEFT, 
		std::make_shared<UI_Image>(
			menuGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			menuGraphic
		),
		std::make_shared<UI_Text>(
			Vector2<float>{ 
				static_cast<float>(GetDrawStringWidthToHandle("Title", 5, font_->GetHandle())),
				static_cast<float>(font_->GetFontSize())
			}, 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER,
			font_, 
			"Title", 
			0xFFFFFF
		),
		std::make_shared<UI_Button>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
			std::make_shared<UI_Image>(
				buttonGraphic.lock()->GetSize().ToVector2f(), 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				buttonGraphic
			),
			std::make_shared<UI_Text>(
				Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				font_, 
				"Button3", 
				0xFFFFFF
			)
		),
		std::make_shared<UI_Button>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
			std::make_shared<UI_Image>(
				buttonGraphic.lock()->GetSize().ToVector2f(), 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				buttonGraphic
			),
			std::make_shared<UI_Text>(
				Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				font_, 
				"Button3", 
				0xFFFFFF
			)
		),
		std::make_shared<UI_Button>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
			std::make_shared<UI_Image>(
				buttonGraphic.lock()->GetSize().ToVector2f(), 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				buttonGraphic
			),
			std::make_shared<UI_Text>(
				Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				font_, 
				"Button3", 
				0xFFFFFF
			)
		),
		std::make_shared<UI_Button>(
			buttonGraphic.lock()->GetSize().ToVector2f(), 
			UI::UI_ORIGIN_TYPE::CENTER_CENTER, 
			std::make_shared<UI_Image>(
				buttonGraphic.lock()->GetSize().ToVector2f(), 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				buttonGraphic
			),
			std::make_shared<UI_Text>(
				Vector2<float>{ 
		static_cast<float>(GetDrawStringWidthToHandle("Button3", 7, font_->GetHandle())),
			static_cast<float>(font_->GetFontSize())
	}, 
				UI::UI_ORIGIN_TYPE::CENTER_CENTER,
				font_, 
				"Button3", 
				0xFFFFFF
			)
		)
	);
	uiSystemMenu_->Init();
	uiSystemMenu_->SetTransformData(
		{ 0.0f, 0.0f },
		0.0f,
		{ 1.0f, 1.0f }
	);

	uiSystemMenuRenderer_ = std::make_shared<UI_UISystemMenuRenderer>(false, std::dynamic_pointer_cast<UI_UISystemMenu>(uiSystemMenu_));




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
	
	auto child = std::dynamic_pointer_cast<GameObject2D>(uiSystemMenu_);
	if(CheckHitKey(KEY_INPUT_UP)) child->GetTransform().localPos_.y--;
	if(CheckHitKey(KEY_INPUT_LEFT)) child->GetTransform().localPos_.x--;
	if(CheckHitKey(KEY_INPUT_DOWN)) child->GetTransform().localPos_.y++;
	if(CheckHitKey(KEY_INPUT_RIGHT)) child->GetTransform().localPos_.x++;

	uiImage_->Update();
	uiText_->Update();
	uiButton_->Update();
	uiSystemMenu_->Update();
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

	uiImageRenderer_->Begin();
	uiImageRenderer_->Render();
	uiImageRenderer_->End();

	uiImageRenderer2_->Begin();
	uiImageRenderer2_->Render();
	uiImageRenderer2_->End();

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

	uiSystemMenuRenderer_->Begin();
	uiSystemMenuRenderer_->Render();
	uiSystemMenuRenderer_->End();

	uiTextRenderer_->Begin();
	uiTextRenderer_->Render();
	uiTextRenderer_->End();

	uiTextRenderer2_->Begin();
	uiTextRenderer2_->Render();
	uiTextRenderer2_->End();
}

void UISystemScene::Release(void) {
	uiButton_->Release();
	uiButton2_->Release();
	uiButton3_->Release();
}

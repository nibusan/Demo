#include "UILayer.h"
#include "../../../../Managers/ResourceManager.h"
#include "../../../../Managers/RenderManager.h"
#include "../../../../Managers/JsonReader.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "../UI/UI_Info.h"
#include "../UI/UIFactory.h"
#include "../UI/AbstractUI.h"
#include "../UI/Parts/Image/UI_Image.h"
#include "../UI/Parts/Image/UI_ImageRenderer.h"
#include "../UI/Parts/Text/UI_Text.h"
#include "../UI/Parts/Text/UI_TextRenderer.h"
#include "../UI/Original/Button/UI_Button.h"
#include "../UI/Original/Button/UI_ButtonRenderer.h"
#include "../UI/Original/Inventory/UI_Inventory.h"
#include "../UI/Original/Inventory/UI_InventoryRenderer.h"
#include "../UI/Original/Item/UI_Item.h"
#include "../UI/Original/Item/UI_ItemRenderer.h"
#include "../UI/Original/UISystemMenu/UI_UISystemMenu.h"
#include "../UI/Original/UISystemMenu/UI_UISystemMenuRenderer.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../Common/Handle/Font/Font.h"
#include "UILayer.h"

void UILayer::Init(void) {
	for (const auto& ui : uis_) {
		ui->Init();
	}
}

void UILayer::Update(void) {
	for (const auto& ui : uis_) {
		ui->Update();
	}
}

void UILayer::Release(void) {
	for (const auto& ui : uis_) {
		ui->Release();
	}
}

void UILayer::LoadUILayer(UILayerInfo::TYPE type) {
	// リソースファイルリスト(json)の読み込み
	const auto uiLayerListJson = JsonReader::GetInstance().Parse("Assets/UILayerList/UILayerList.json");

	std::string te = uiLayerListJson["UILayerListPath"][static_cast<int>(type)];
	const auto uiLayerJson = JsonReader::GetInstance().Parse("Assets/" + te);

	auto& resourceManager = ResourceManager::GetInstance();
	auto& renderManager = RenderManager::GetInstance();
	auto& uiFactory = UIFactory::GetInstance();

	for (const auto& ui : uiLayerJson["UIs"]) {
		// 生成したUIを格納
		std::shared_ptr<AbstractUI> createUI;
		
		// 生成したUIのレンダラー格納
		std::shared_ptr<AbstractRenderer> createUIRenderer;

		// 生成するUIの種類
		UI::UI_TYPE uiType = (UI::TAG_TO_UI_TYPE.find(static_cast<std::string>(ui["Type"])))->second;
		
		// 描画する際に使用するピクセルシェーダー
		std::weak_ptr<PixelShader> pixelShader;

		// ピクセルシェーダーのキーが設定されていたらセットする
		if (ui["Attribute"]["PixelShaderResourceKey"] != nullptr) {
			pixelShader = 
				std::dynamic_pointer_cast<PixelShader>(resourceManager.GetResourceFile(static_cast<std::string>(ui["Attribute"]["PixelShaderResourceKey"])).lock());
			PixelShaderEventManager::GetInstance().InitPixelShader(ui["Attribute"]["PixelShaderEventID"], pixelShader);
		}
		switch (uiType) {
		case UI::UI_TYPE::IMAGE: {
			std::weak_ptr<Graphic> image = 
				std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(ui["Attribute"]["ImageResourceKey"])).lock());

			createUI = uiFactory.CreateUI<UI_Image>(
				ui["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(ui["CanvasSize"]["Width"], ui["CanvasSize"]["Height"]),
				static_cast<UI::UI_ORIGIN_TYPE>(ui["OriginType"]),
				ui["IsClickable"],
				(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(ui["OnClickEventID"])))->second,
				pixelShader,
				ui["Attribute"]["PixelShaderEventID"],
				image
			);
			createUIRenderer = std::make_shared<UI_ImageRenderer>(false, std::dynamic_pointer_cast<UI_Image>(createUI));
			break;
		}
		case UI::UI_TYPE::TEXT: {
			// 使用するフォントの生成
			std::shared_ptr<Font> font =
				std::make_shared<Font>(
					std::dynamic_pointer_cast<Font>(resourceManager.GetResourceFile(static_cast<std::string>(ui["Attribute"]["FontResourceKey"])).lock()

				)->GetFontName(),
				static_cast<int>(ui["Attribute"]["TextSize"])
			);
			
			std::string text = "aiueoooo";
			createUI = uiFactory.CreateUI<UI_Text>(
				ui["CanvasSize"] == nullptr
					? Vector2<float>( 
						static_cast<float>(GetDrawStringWidthToHandle(text.c_str(), text.length(), font->GetHandle())), 
						static_cast<float>(font->GetFontSize()))
					: Vector2<float>(ui["CanvasSize"]["Width"], ui["CanvasSize"]["Height"]),
				static_cast<UI::UI_ORIGIN_TYPE>(ui["OriginType"]),
				ui["IsClickable"],
				(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(ui["OnClickEventID"])))->second,
				pixelShader,
				ui["Attribute"]["PixelShaderEventID"],
				font,
				text,
				0xFFFFFF
			);
			createUIRenderer = std::make_shared<UI_TextRenderer>(false, std::dynamic_pointer_cast<UI_Text>(createUI));
			break;
		}
		/*case UI::UI_TYPE::BUTTON: {

			break;
		}
		case UI::UI_TYPE::UI_SYSTEM_MENU: {
			break;
		}
		case UI::UI_TYPE::INVENTORY: {
			break;
		}
		case UI::UI_TYPE::ITEM: {
			break;
		}*/
		case UI::UI_TYPE::NONE:
		default:
			break;
		}

		createUI->Init();
		createUI->SetTransformData(
			{ ui["Pos"]["X"], ui["Pos"]["Y"] },
			ui["Rot"],
			{ ui["Scl"]["X"], ui["Scl"]["Y"] }
		);

		renderManager.AddRenderer2D(createUIRenderer);
		uis_.emplace_back(createUI);
	}
}

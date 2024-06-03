#include "AbstractUILayer.h"
#include "../../../../Managers/ResourceManager.h"
#include "../../../../Managers/RenderManager.h"
#include "../../../../Managers/JsonReader.h"
#include "../UI/UI_Info.h"
#include "../UI/UIFactory.h"
#include "../UI/AbstractUI.h"
#include "../UI/Parts/Image/UI_Image.h"
#include "../UI/Parts/Text/UI_Text.h"
#include "../UI/Original/Button/UI_Button.h"
#include "../UI/Original/Inventory/UI_Inventory.h"
#include "../UI/Original/Item/UI_Item.h"
#include "../UI/Original/UISystemMenu/UI_UISystemMenu.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"

void AbstractUILayer::LoadUILayer(UILayer::TYPE type) {
	// リソースファイルリスト(json)の読み込み
	const auto uiLayerListJson = JsonReader::GetInstance().Parse("Assets/UILayerList/UILayerList.json");

	const auto uiLayerJson = JsonReader::GetInstance().Parse("Assets/" + uiLayerListJson["UILayerListPath"][static_cast<int>(type)]);

	auto& resourceManager = ResourceManager::GetInstance();
	auto& renderManager = RenderManager::GetInstance();
	auto& uiFactory = UIFactory::GetInstance();

	for (const auto& ui : uiLayerJson["UIs"]) {
		// 生成したUIを格納
		std::shared_ptr<AbstractUI> createUI;

		// 生成するUIの種類
		UI::UI_TYPE uiType = (UI::TAG_TO_UI_TYPE.find(static_cast<std::string>(ui["Type"])))->second;
		
		switch (uiType) {
		case UI::UI_TYPE::IMAGE: {
			std::weak_ptr<Graphic> image = 
				std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(ui["Attribute"]["ImageResourceKey"])).lock());

			createUI = uiFactory.CreateUI(
				uiType,
				ui["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(ui["CanvasSize"]["Width"], ui["CanvasSize"]["Height"]),
				static_cast<UI::UI_ORIGIN_TYPE>(ui["OriginType"]),
				image
			);
			break;
		}
		case UI::UI_TYPE::TEXT: {
			std::weak_ptr<Graphic> font = 
				std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(ui["Attribute"]["ImageResourceKey"])).lock());

			createUI = uiFactory.CreateUI(
				uiType,
				ui["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(ui["CanvasSize"]["Width"], ui["CanvasSize"]["Height"]),
				static_cast<UI::UI_ORIGIN_TYPE>(ui["OriginType"]),
				image
			);
			break;
		}
		case UI::UI_TYPE::BUTTON: {
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
		}
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
		createUI->SetClickable(ui["IsClickable"]);
		createUI->SetOnClickCallBack(nullptr);

		uis_.emplace_back(createUI);
	}
}

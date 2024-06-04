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
#include "../../../../Common/Handle/Sound/Sound.h"
#include "../../../../Common/Handle/Font/Font.h"
#include "../../../../Common/Handle/PixelShader/PixelShader.h"
#include "../../../../Managers/ResourceManager.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "UIFactory.h"

std::shared_ptr<AbstractUI> UIFactory::CreateUI(const nlohmann::json& uiData, bool isCreateRenderer) const {
	// リソースファイル取得用
	auto& resourceManager = ResourceManager::GetInstance();

	// 生成するUI
	std::shared_ptr<AbstractUI> createUI;

	// 生成するUIのレンダラー
	std::shared_ptr<AbstractUIRenderer> createUIRenderer;

	//生成するUIの種類
	UI::UI_TYPE uiType = (UI::TAG_TO_UI_TYPE.find(static_cast<std::string>(uiData["Type"])))->second;

	// 描画する際に使用するピクセルシェーダー
	std::weak_ptr<PixelShader> pixelShader;

	// ピクセルシェーダーのキーが設定されていたらセットする
	if (uiData["Attribute"]["PixelShaderResourceKey"] != nullptr) {
		pixelShader =
			std::dynamic_pointer_cast<PixelShader>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["PixelShaderResourceKey"])).lock());
		PixelShaderEventManager::GetInstance().InitPixelShader(uiData["Attribute"]["PixelShaderEventID"], pixelShader);
	}

	// 各UIの生成処理
	switch (uiType) {
	case UI::UI_TYPE::IMAGE: {
		// 画像を取得
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["ImageResourceKey"])).lock());

		// UIの生成
		createUI = std::make_shared<UI_Image>(
			uiData["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(uiData["CanvasSize"]["Width"], uiData["CanvasSize"]["Height"]),
			static_cast<UI::UI_ORIGIN_TYPE>(uiData["OriginType"]),
			uiData["IsClickable"],
			(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(uiData["OnClickEventID"])))->second,
			pixelShader,
			uiData["Attribute"]["PixelShaderEventID"],
			image
		);

		// コライダーの構築
		createUI->CreateCollider<CircleCollider>(Vector2<float>(0.0f, 0.0f), 1.0f);
		
		if (isCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_ImageRenderer>(false, std::dynamic_pointer_cast<UI_Image>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::TEXT: {
		// 使用するフォントの生成
		std::shared_ptr<Font> font =
			std::make_shared<Font>(
				std::dynamic_pointer_cast<Font>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["FontResourceKey"])).lock()

				)->GetFontName(),
				static_cast<int>(uiData["Attribute"]["TextSize"])
			);

		std::string text = "aiueoooo";

		// UIの生成
		createUI = std::make_shared<UI_Text>(
			uiData["CanvasSize"] == nullptr
			? Vector2<float>(
				static_cast<float>(GetDrawStringWidthToHandle(text.c_str(), text.length(), font->GetHandle())),
				static_cast<float>(font->GetFontSize()))
			: Vector2<float>(uiData["CanvasSize"]["Width"], uiData["CanvasSize"]["Height"]),
			static_cast<UI::UI_ORIGIN_TYPE>(uiData["OriginType"]),
			uiData["IsClickable"],
			(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(uiData["OnClickEventID"])))->second,
			pixelShader,
			uiData["Attribute"]["PixelShaderEventID"],
			font,
			text,
			0xFFFFFF
		);

		// コライダーの構築
		createUI->CreateCollider<RectCollider>(Vector2<float>(0.0f, 0.0f), Vector2<float>(100.0f, 100.0f));
		
		if (isCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_TextRenderer>(false, std::dynamic_pointer_cast<UI_Text>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::BUTTON: {
		// 画像を取得
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(
				resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["UI_Image"]["Attribute"]["ImageResourceKey"])).lock());
		
		// UIの生成
		createUI = std::make_shared<UI_Button>(
			uiData["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(uiData["CanvasSize"]["Width"], uiData["CanvasSize"]["Height"]),
			static_cast<UI::UI_ORIGIN_TYPE>(uiData["OriginType"]),
			uiData["IsClickable"],
			(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(uiData["OnClickEventID"])))->second,
			pixelShader,
			uiData["Attribute"]["PixelShaderEventID"],
			std::dynamic_pointer_cast<UI_Image>(CreateUI(uiData["Attribute"]["UI_Image"], false)),
			std::dynamic_pointer_cast<UI_Text>(CreateUI(uiData["Attribute"]["UI_Text"], false))
		);

		// コライダーの構築
		createUI->CreateCollider<RectCollider>(Vector2<float>(0.0f, 0.0f), Vector2<float>(100.0f, 100.0f));

		if (isCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_ButtonRenderer>(false, std::dynamic_pointer_cast<UI_Button>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
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

	// 初期化
	createUI->Init();

	// 子が存在する場合は子を生成してから自身の子として追加する
	for (const auto& child : uiData["Child"]) {
		auto childUI = CreateUI(child, true);
		createUI->AddChild(childUI);
	}

	// 基礎データをセット
	createUI->SetTransformData(
		{ uiData["Pos"]["X"], uiData["Pos"]["Y"] },
		uiData["Rot"],
		uiData["Scl"]
	);

	// コライダーの構築
	if (uiData["IsClickable"]) {
		createUI->CreateCollider<RectCollider>({ uiData["Pos"]["X"], uiData["Pos"]["Y"] }, createUI->GetRenderCanvas().lock()->GetSize().ToVector2f() / 2.0f);
	}

	if (uiData["Attribute"]["SelectSoundResourceKey"] != nullptr) {
		createUI->SetSelectSound(
			std::dynamic_pointer_cast<Sound>(resourceManager.GetResourceFile(uiData["Attribute"]["SelectSoundResourceKey"]).lock())
		);
	}

	return createUI;
}
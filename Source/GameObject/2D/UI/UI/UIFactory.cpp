#include "../UI/Parts/Image/UI_Image.h"
#include "../UI/Parts/Image/UI_ImageRenderer.h"
#include "../UI/Parts/Text/UI_Text.h"
#include "../UI/Parts/Text/UI_TextRenderer.h"
#include "../UI/Original/Button/UI_Button.h"
#include "../UI/Original/Button/UI_ButtonRenderer.h"
#include "../UI/Original/Inventory/UI_Inventory.h"
#include "../UI/Original/Inventory/UI_InventoryRenderer.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../Common/Handle/Sound/Sound.h"
#include "../../../../Common/Handle/Font/Font.h"
#include "../../../../Common/Handle/PixelShader/PixelShader.h"
#include "../../../../Managers/ResourceManager.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "../../../../Data/MessageList/MessageList.h"
#include "../../../../Utility/Utility.h"
#include "UIFactory.h"

std::shared_ptr<AbstractUI> UIFactory::CreateUI(const nlohmann::json& uiData, bool shouldCreateRenderer, bool useLocalPos) const {
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

		if (shouldCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_ImageRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Image>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::TEXT: {
		// 使用するフォントの生成
		std::shared_ptr<Font> font =
			std::make_shared<Font>(
				std::dynamic_pointer_cast<Font>(
					resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["FontResourceKey"])).lock())->GetFontName(),
				static_cast<int>(uiData["Attribute"]["TextSize"])
			);

		// 描画するテキストを取得する
		auto text = Utility::WStringToString(MessageList::GetInstance().GetMessage_(uiData["Attribute"]["TextID"]));

		// UIの生成
		createUI = std::make_shared<UI_Text>(
			uiData["CanvasSize"] == nullptr
			? Vector2<float>(
				static_cast<float>(GetDrawStringWidthToHandle(text.c_str(), static_cast<int>(text.length()), font->GetHandle())),
				static_cast<float>(font->GetFontSize()))
			: Vector2<float>(uiData["CanvasSize"]["Width"], uiData["CanvasSize"]["Height"]),
			static_cast<UI::UI_ORIGIN_TYPE>(uiData["OriginType"]),
			uiData["IsClickable"],
			(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(uiData["OnClickEventID"])))->second,
			pixelShader,
			uiData["Attribute"]["PixelShaderEventID"],
			font,
			text,
			std::stoi(std::string(uiData["Attribute"]["TextColor"]), nullptr, 16)
		);

		if (shouldCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_TextRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Text>(createUI));

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
			std::dynamic_pointer_cast<UI_Image>(CreateUI(uiData["Attribute"]["UI_Image"], false, true)),
			std::dynamic_pointer_cast<UI_Text>(CreateUI(uiData["Attribute"]["UI_Text"], false, true))
		);

		if (shouldCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_ButtonRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Button>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::INVENTORY: {
		// アイテム画像を取得
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["Items_ImageResourceKey"])).lock());

		// UIの生成
		createUI = std::make_shared<UI_Inventory>(
			uiData["CanvasSize"] == nullptr ? image.lock()->GetSize().ToVector2f() : Vector2<float>(uiData["CanvasSize"]["Width"], uiData["CanvasSize"]["Height"]),
			static_cast<UI::UI_ORIGIN_TYPE>(uiData["OriginType"]),
			uiData["IsClickable"],
			(UI::ON_CLICK_EVENT_LIST.find(static_cast<int>(uiData["OnClickEventID"])))->second,
			pixelShader,
			uiData["Attribute"]["PixelShaderEventID"],
			nullptr,
			std::dynamic_pointer_cast<UI_Image>(CreateUI(uiData["Attribute"]["BackGround_UIImage"], false, true)),
			image
		);

		if (shouldCreateRenderer) {
			// UIのレンダラーを生成
			createUIRenderer = std::make_shared<UI_InventoryRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Inventory>(createUI));

			// 生成したUIのレンダラーを登録する
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
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
		auto childUI = CreateUI(child, true, false);
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
		auto b = Collider_Info::TAG_TO_COLLIDER_TYPE.find(static_cast<std::string>(uiData["Collider"]["Type"]));
		switch (Collider_Info::TAG_TO_COLLIDER_TYPE.find(static_cast<std::string>(uiData["Collider"]["Type"]))->second) {
		case Collider_Info::TYPE::CIRCLE:
			createUI->CreateCollider<CircleCollider>(
				Vector2<float>(uiData["Pos"]["X"], uiData["Pos"]["Y"]),
				uiData["Collider"]["Attribute"]["Radius"]
			);
			break;
		case Collider_Info::TYPE::RECT:
			createUI->CreateCollider<RectCollider>(
				Vector2<float>(uiData["Pos"]["X"], uiData["Pos"]["Y"]),
				uiData["Collider"]["Attribute"]["Size"] == nullptr
				? createUI->GetRenderCanvas().lock()->GetSize().ToVector2f() / 2.0f
				: Vector2<float>(uiData["Collider"]["Attribute"]["Size"]["Width"], uiData["Collider"]["Attribute"]["Size"]["Height"])
			);
			break;
		case Collider_Info::TYPE::NONE:
		default:
			break;
		}
	}

	// カーソルを合わせた際に鳴らす効果音をセット
	if (uiData["Attribute"]["SelectSoundResourceKey"] != nullptr) {
		createUI->SetSelectSound(
			std::dynamic_pointer_cast<Sound>(resourceManager.GetResourceFile(uiData["Attribute"]["SelectSoundResourceKey"]).lock())
		);
	}

	// クリックした際に鳴らす効果音をセット
	if (uiData["Attribute"]["ClickSoundResourceKey"] != nullptr) {
		createUI->SetOnClickSound(
			std::dynamic_pointer_cast<Sound>(resourceManager.GetResourceFile(uiData["Attribute"]["ClickSoundResourceKey"]).lock())
		);
	}

	return createUI;
}
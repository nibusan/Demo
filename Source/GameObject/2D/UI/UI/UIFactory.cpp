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
	// ���\�[�X�t�@�C���擾�p
	auto& resourceManager = ResourceManager::GetInstance();

	// ��������UI
	std::shared_ptr<AbstractUI> createUI;

	// ��������UI�̃����_���[
	std::shared_ptr<AbstractUIRenderer> createUIRenderer;

	//��������UI�̎��
	UI::UI_TYPE uiType = (UI::TAG_TO_UI_TYPE.find(static_cast<std::string>(uiData["Type"])))->second;

	// �`�悷��ۂɎg�p����s�N�Z���V�F�[�_�[
	std::weak_ptr<PixelShader> pixelShader;

	// �s�N�Z���V�F�[�_�[�̃L�[���ݒ肳��Ă�����Z�b�g����
	if (uiData["Attribute"]["PixelShaderResourceKey"] != nullptr) {
		pixelShader =
			std::dynamic_pointer_cast<PixelShader>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["PixelShaderResourceKey"])).lock());
		PixelShaderEventManager::GetInstance().InitPixelShader(uiData["Attribute"]["PixelShaderEventID"], pixelShader);
	}

	// �eUI�̐�������
	switch (uiType) {
	case UI::UI_TYPE::IMAGE: {
		// �摜���擾
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["ImageResourceKey"])).lock());

		// UI�̐���
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
			// UI�̃����_���[�𐶐�
			createUIRenderer = std::make_shared<UI_ImageRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Image>(createUI));

			// ��������UI�̃����_���[��o�^����
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::TEXT: {
		// �g�p����t�H���g�̐���
		std::shared_ptr<Font> font =
			std::make_shared<Font>(
				std::dynamic_pointer_cast<Font>(
					resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["FontResourceKey"])).lock())->GetFontName(),
				static_cast<int>(uiData["Attribute"]["TextSize"])
			);

		// �`�悷��e�L�X�g���擾����
		auto text = Utility::WStringToString(MessageList::GetInstance().GetMessage_(uiData["Attribute"]["TextID"]));

		// UI�̐���
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
			// UI�̃����_���[�𐶐�
			createUIRenderer = std::make_shared<UI_TextRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Text>(createUI));

			// ��������UI�̃����_���[��o�^����
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::BUTTON: {
		// �摜���擾
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(
				resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["UI_Image"]["Attribute"]["ImageResourceKey"])).lock());
		
		// UI�̐���
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
			// UI�̃����_���[�𐶐�
			createUIRenderer = std::make_shared<UI_ButtonRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Button>(createUI));

			// ��������UI�̃����_���[��o�^����
			RenderManager::GetInstance().AddRenderer2D(createUIRenderer);
		}
		break;
	}
	case UI::UI_TYPE::INVENTORY: {
		// �A�C�e���摜���擾
		std::weak_ptr<Graphic> image =
			std::dynamic_pointer_cast<Graphic>(resourceManager.GetResourceFile(static_cast<std::string>(uiData["Attribute"]["Items_ImageResourceKey"])).lock());

		// UI�̐���
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
			// UI�̃����_���[�𐶐�
			createUIRenderer = std::make_shared<UI_InventoryRenderer>(useLocalPos, std::dynamic_pointer_cast<UI_Inventory>(createUI));

			// ��������UI�̃����_���[��o�^����
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

	// ������
	createUI->Init();

	// �q�����݂���ꍇ�͎q�𐶐����Ă��玩�g�̎q�Ƃ��Ēǉ�����
	for (const auto& child : uiData["Child"]) {
		auto childUI = CreateUI(child, true, false);
		createUI->AddChild(childUI);
	}

	// ��b�f�[�^���Z�b�g
	createUI->SetTransformData(
		{ uiData["Pos"]["X"], uiData["Pos"]["Y"] },
		uiData["Rot"],
		uiData["Scl"]
	);

	// �R���C�_�[�̍\�z
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

	// �J�[�\�������킹���ۂɖ炷���ʉ����Z�b�g
	if (uiData["Attribute"]["SelectSoundResourceKey"] != nullptr) {
		createUI->SetSelectSound(
			std::dynamic_pointer_cast<Sound>(resourceManager.GetResourceFile(uiData["Attribute"]["SelectSoundResourceKey"]).lock())
		);
	}

	// �N���b�N�����ۂɖ炷���ʉ����Z�b�g
	if (uiData["Attribute"]["ClickSoundResourceKey"] != nullptr) {
		createUI->SetOnClickSound(
			std::dynamic_pointer_cast<Sound>(resourceManager.GetResourceFile(uiData["Attribute"]["ClickSoundResourceKey"]).lock())
		);
	}

	return createUI;
}
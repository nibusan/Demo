#pragma once
#include <memory>
#include "../../../../Common/StaticSingleton.h"
#include "AbstractUI.h"
#include "UI_Info.h"
#include "../UI/Parts/Image/UI_Image.h"
#include "../UI/Parts/Text/UI_Text.h"
#include "../UI/Original/Button/UI_Button.h"
#include "../UI/Original/Inventory/UI_Inventory.h"
#include "../UI/Original/Item/UI_Item.h"
#include "../UI/Original/UISystemMenu/UI_UISystemMenu.h"

class UIFactory : public StaticSingleton<UIFactory> {
public:
	~UIFactory(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIFactory);

	template <typename... Args>
	std::shared_ptr<AbstractUI> CreateUI(UI::UI_TYPE type, Args&&... args) const;
private:


	UIFactory(void) = default;
};

template<typename ...Args>
inline std::shared_ptr<AbstractUI> UIFactory::CreateUI(UI::UI_TYPE type, Args && ...args) const {

	// éÌóﬁÇ…ÇÊÇ¡Çƒê∂ê¨Ç∑ÇÈÉNÉâÉXÇïœÇ¶ÇÈ
	switch (type) {
	case UI::UI_TYPE::IMAGE: {
		return std::make_shared<UI_Image>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::TEXT: {
		return std::make_shared<UI_Text>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::BUTTON: {
		return std::make_shared<UI_Button>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::UI_SYSTEM_MENU: {
		return std::make_shared<UI_UISystemMenu>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::INVENTORY: {
		return std::make_shared<UI_Inventory>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::ITEM: {
		//createUI = std::make_shared<UI_Item>(std::forward<Args>(args)...);
		break;
	}
	case UI::UI_TYPE::NONE:
	default:
		break;
	}
}

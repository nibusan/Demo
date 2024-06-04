#pragma once
#include <memory>
#include "../../../../Common/StaticSingleton.h"
#include "../../../../Managers/RenderManager.h"
#include "../../../../Library/nlohmann-json/json.hpp"
#include "AbstractUI.h"

class UIFactory : public StaticSingleton<UIFactory> {
public:
	~UIFactory(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIFactory);

	/// @brief UIのインスタンスを生成
	std::shared_ptr<AbstractUI> CreateUI(const nlohmann::json& uiData, bool isCreateRenderer) const;
private:

	UIFactory(void) = default;
};
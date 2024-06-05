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
	/// @param uiData UIのデータが格納されたjson
	/// @param shouldCreateRenderer レンダラーを生成するか
	/// @param useLocalPos 生成するUIを描画する際にローカル座標だけを参照するか
	/// @return 生成済みのUI
	std::shared_ptr<AbstractUI> CreateUI(const nlohmann::json& uiData, bool shouldCreateRenderer, bool useLocalPos) const;
private:

	UIFactory(void) = default;
};
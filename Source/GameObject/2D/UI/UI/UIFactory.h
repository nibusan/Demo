#pragma once
#include <memory>
#include "../../../../Common/StaticSingleton.h"
#include "../../../../Managers/RenderManager.h"

class UIFactory : public StaticSingleton<UIFactory> {
public:
	~UIFactory(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIFactory);
	
	/// @brief UIのインスタンスを生成
	/// @tparam T 生成するUIのクラス
	/// @tparam TRenderer 生成するUIのレンダラークラス
	/// @tparam ...Args 各UIに渡す引数
	/// @param ...args UIに渡す引数
	/// @return 生成したUIのインスタンス
	template <typename T, typename... Args>
	std::shared_ptr<T> CreateUI(Args&&... args) const;
private:

	UIFactory(void) = default;
};

template<typename T, typename ...Args>
inline std::shared_ptr<T> UIFactory::CreateUI(Args&& ...args) const {
	return std::make_shared<T>(args...);;
}
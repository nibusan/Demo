#pragma once
#include <memory>
#include "../../../../Common/StaticSingleton.h"
#include "../../../../Managers/RenderManager.h"

class UIFactory : public StaticSingleton<UIFactory> {
public:
	~UIFactory(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIFactory);
	
	/// @brief UI�̃C���X�^���X�𐶐�
	/// @tparam T ��������UI�̃N���X
	/// @tparam TRenderer ��������UI�̃����_���[�N���X
	/// @tparam ...Args �eUI�ɓn������
	/// @param ...args UI�ɓn������
	/// @return ��������UI�̃C���X�^���X
	template <typename T, typename... Args>
	std::shared_ptr<T> CreateUI(Args&&... args) const;
private:

	UIFactory(void) = default;
};

template<typename T, typename ...Args>
inline std::shared_ptr<T> UIFactory::CreateUI(Args&& ...args) const {
	return std::make_shared<T>(args...);;
}
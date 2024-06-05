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

	/// @brief UI�̃C���X�^���X�𐶐�
	/// @param uiData UI�̃f�[�^���i�[���ꂽjson
	/// @param shouldCreateRenderer �����_���[�𐶐����邩
	/// @param useLocalPos ��������UI��`�悷��ۂɃ��[�J�����W�������Q�Ƃ��邩
	/// @return �����ς݂�UI
	std::shared_ptr<AbstractUI> CreateUI(const nlohmann::json& uiData, bool shouldCreateRenderer, bool useLocalPos) const;
private:

	UIFactory(void) = default;
};
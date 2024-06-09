#pragma once
#include <string>
#include <unordered_map>

namespace Collider_Info {

	/// @brief �R���C�_�[�̎��
	enum class TYPE {
		NONE = -1,
		CIRCLE,		// �~
		RECT		// ��`
	};

	/// @brief json�Ŏg���Ă���^�O(�L�[)��UI_TYPE�ɕϊ�����A�z�z��
	static const std::unordered_map<std::string, TYPE> TAG_TO_COLLIDER_TYPE {
		{ "Circle",	TYPE::CIRCLE },
		{ "Rect",	TYPE::RECT }
	};
}
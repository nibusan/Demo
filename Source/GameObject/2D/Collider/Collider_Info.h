#pragma once
#include <string>
#include <unordered_map>

namespace Collider_Info {

	/// @brief コライダーの種類
	enum class TYPE {
		NONE = -1,
		CIRCLE,		// 円
		RECT		// 矩形
	};

	/// @brief jsonで使っているタグ(キー)をUI_TYPEに変換する連想配列
	static const std::unordered_map<std::string, TYPE> TAG_TO_COLLIDER_TYPE {
		{ "Circle",	TYPE::CIRCLE },
		{ "Rect",	TYPE::RECT }
	};
}
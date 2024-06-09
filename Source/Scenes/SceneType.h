#pragma once

namespace Scene {	
	/// @brief シーンの種類
	enum class TYPE {
		NONE = -1,
		INVENTORY_SYSTEM,	// インベントリシステム
		UI_SYSTEM,			// UIシステム
		MAX					// 要素数カウント用
	};
}
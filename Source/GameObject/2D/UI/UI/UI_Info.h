#pragma once
namespace UI {
	// UIの種類
	enum class UI_TYPE {
		NONE,	// なし
		IMAGE,	// 画像
		TEXT,	// テキスト
		BUTTON	// ボタン
	};

	// UIのどこを原点として配置するか
	enum class UI_ORIGIN_TYPE {
		UP_LEFT,		// 上段 左
		UP_CENTER,		// 上段 中心
		UP_RIGHT,		// 上段 右
		CENTER_LEFT,	// 中段 左
		CENTER_CENTER,	// 中段 中心
		CENTER_RIGHT,	// 中段 右
		DOWN_LEFT,		// 下段 左
		DOWN_CENTER,	// 下段 中心
		DOWN_RIGHT		// 下段 右
	};
}
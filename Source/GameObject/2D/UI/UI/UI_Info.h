#pragma once
#include <string>
#include <unordered_map>
#include "../../../../Managers/SceneManager.h"
//#include "../../../../Debug/DebugLog.h"

namespace UI {
	// UIの種類
	enum class UI_TYPE {
		NONE,			// なし
		IMAGE,			// 画像
		TEXT,			// テキスト
		BUTTON,			// ボタン
		UI_SYSTEM_MENU,	// UISystemSceneで使うメニュー
		INVENTORY,		// インベントリ
		ITEM			// アイテム
	};

	// jsonで使っているタグ(キー)をUI_TYPEに変換する連想配列
	static const std::unordered_map<std::string, UI_TYPE> TAG_TO_UI_TYPE {
		{ "Image",			UI_TYPE::IMAGE },
		{ "Text",			UI_TYPE::TEXT },
		{ "Button",			UI_TYPE::BUTTON },
		{ "UISystemMenu",	UI_TYPE::UI_SYSTEM_MENU },
		{ "Inventory",		UI_TYPE::INVENTORY },
		{ "Item",			UI_TYPE::ITEM },
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

	// UIがクリックされた際に呼ばれるコールバック関数を管理
	static const std::unordered_map<int, std::function<void(void)>> ON_CLICK_EVENT_LIST = {
		{
			-1, nullptr
		},
		{ 
			0,[]() {
				//DebugLog::GetInstance().AddLog({3.0f,"OnClick : 0", 0x00FF00});
			}
		},
		{ 
			1,[]() {
				//DebugLog::GetInstance().AddLog({3.0f,"OnClick : 1", 0x00FF00});
			}
		},
		{ 
			2,[]() {
				//DebugLog::GetInstance().AddLog({3.0f,"OnClick : 2", 0x00FF00});
			}
		},
		{ 
			3,[]() {
				//DebugLog::GetInstance().AddLog({3.0f,"OnClick : 3", 0x00FF00});
			}
		},
		{
			4,[]() {
				SceneManager::GetInstance().SetNextScene(Scene::TYPE::INVENTORY_SYSTEM);
				//DebugLog::GetInstance().AddLog({3.0f,"SceneChanged", 0x0000FF});
			}
		}
	};
}

#pragma once
#include <string>
#include <unordered_map>
#include "../../../../Managers/SceneManager.h"
//#include "../../../../Debug/DebugLog.h"

namespace UI {
	// UI�̎��
	enum class UI_TYPE {
		NONE,			// �Ȃ�
		IMAGE,			// �摜
		TEXT,			// �e�L�X�g
		BUTTON,			// �{�^��
		UI_SYSTEM_MENU,	// UISystemScene�Ŏg�����j���[
		INVENTORY,		// �C���x���g��
		ITEM			// �A�C�e��
	};

	// json�Ŏg���Ă���^�O(�L�[)��UI_TYPE�ɕϊ�����A�z�z��
	static const std::unordered_map<std::string, UI_TYPE> TAG_TO_UI_TYPE {
		{ "Image",			UI_TYPE::IMAGE },
		{ "Text",			UI_TYPE::TEXT },
		{ "Button",			UI_TYPE::BUTTON },
		{ "UISystemMenu",	UI_TYPE::UI_SYSTEM_MENU },
		{ "Inventory",		UI_TYPE::INVENTORY },
		{ "Item",			UI_TYPE::ITEM },
	};

	// UI�̂ǂ������_�Ƃ��Ĕz�u���邩
	enum class UI_ORIGIN_TYPE {
		UP_LEFT,		// ��i ��
		UP_CENTER,		// ��i ���S
		UP_RIGHT,		// ��i �E
		CENTER_LEFT,	// ���i ��
		CENTER_CENTER,	// ���i ���S
		CENTER_RIGHT,	// ���i �E
		DOWN_LEFT,		// ���i ��
		DOWN_CENTER,	// ���i ���S
		DOWN_RIGHT		// ���i �E
	};

	// UI���N���b�N���ꂽ�ۂɌĂ΂��R�[���o�b�N�֐����Ǘ�
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

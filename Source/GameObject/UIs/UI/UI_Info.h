#pragma once
namespace UI {
	// UI�̎��
	enum class UI_TYPE {
		NONE,	// �Ȃ�
		IMAGE,	// �摜
		TEXT,	// �e�L�X�g
		BUTTON	// �{�^��
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
}
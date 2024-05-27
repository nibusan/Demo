#pragma once
#include <unordered_map>
#include "../../../Common/Handle/Model/Model.h"

/// @brief ���f���̃A�j���[�V�����Ǘ��ɓ��������\���̂ł�
struct Animation {
	//�f�t�H���g�̃A�j���[�V�����̃X�s�[�h( 1.0 / (�Q�[����FPS / �A�j���[�V������FPS) )
	static constexpr float DEF_ANIM_SPEED = 1.0f / (60.0f / 30.0f);

	struct ANIM_DATA {
		std::string animation_Resource_Key;
		Weak_Model animation;
		int attachNum;
		float totalTime;
		float currentTime;
		float blend;
	};
	std::unordered_map<int, ANIM_DATA> animations_;
	float blendRate_;

	Animation() = default;
	~Animation() = default;
};
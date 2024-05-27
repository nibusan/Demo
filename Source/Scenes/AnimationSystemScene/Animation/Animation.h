#pragma once
#include <unordered_map>
#include "../../../Common/Handle/Model/Model.h"

/// @brief モデルのアニメーション管理に特化した構造体です
struct Animation {
	//デフォルトのアニメーションのスピード( 1.0 / (ゲームのFPS / アニメーションのFPS) )
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
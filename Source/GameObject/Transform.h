#pragma once
#include <concepts>
#include "../Common/Vector2.h"

/// @brief ゲームオブジェクトの基礎データを管理するクラス
/// @note conceptでtemplateの引数を制限してます
/// @tparam T 何次元で管理するか(2D:Vector2<float> or 3D:Vector3<float>)
template <typename T>
concept ValidType_ = 
	// 許容されている型かどうかを判定する
	std::is_same_v<T, Vector2<float>>;
template <ValidType_ T>
class Transform {
public:
	// 座標
	T pos_;
	T localPos_;

	// 角度
	T rot_;
	T localRot_;

	// スケール値
	T scl_;
	T localScl_;

	Transform(void) = default;
	~Transform(void) = default;
};

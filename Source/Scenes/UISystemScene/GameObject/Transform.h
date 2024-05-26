#pragma once

/// @brief ゲームオブジェクトの基礎データを管理するクラス
/// @tparam T 何次元で管理するか(2D:Vector2,3D:Vector3)
template <typename T>
class Transform {
public:
	// 座標
	T pos_;
	T localpos_;

	// 角度
	T rot_;
	T localrot_;

	// スケール値
	T scl_;
	T localscl_;

	Transform(void) = default;
	~Transform(void) = default;
};

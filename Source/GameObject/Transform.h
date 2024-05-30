#pragma once
#include <concepts>
#include "../Common/Vector2.h"

/// @brief ゲームオブジェクトの基礎データを管理するクラス
/// @note 角度は2D、3Dで要素数が変わるので派生クラスで定義してます

/// @brief conceptでtemplateの引数を制限してます
/// @tparam T 何次元で管理するか(2D:Vector2<float> or 3D:Vector3<float>)
template <typename T>
concept VectorType_ = 
	// 許容されている型かどうかを判定する
	std::is_same_v<T, Vector2<float>>;
template <VectorType_ T>
class Transform {
public:
	// parent = 親の値
	// local = 自身の値
	// current = 計算済みの現在の値
	// (parent + local = current)

	// 座標
	T parentPos_;
	T localPos_;
	T currentPos_;

	// スケール値
	T parentScl_;
	T localScl_;
	T currentScl_;

	Transform(void) = default;
	~Transform(void) = default;
};

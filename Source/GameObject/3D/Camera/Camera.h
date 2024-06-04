#pragma once
#include "../GameObject3D.h"

/// @brief カメラのクラスです
class Camera : public GameObject3D {
public:
	// カメラの状態
	enum class STATE {
		NORMAL,		// 通常モード
		FIXED_POINT	// 定点カメラ
	};

	Camera(void) = default;
	~Camera(void) = default;

	/// @brief カメラの状態を変更する
	/// @param state カメラの状態
	void ChangeMode(STATE state);

	/// @brief カメラの情報をセット(毎フレーム呼ぶ必要あり) 
	void SetBeforeDraw(void);
private:
	// 現在のカメラの状態
	STATE state_;

	void Init_GameObject3D(void) override;
	void Update_GameObject3D(void) override;
	void Release_GameObject3D(void) override;

	/// @brief カメラの移動処理(角度も変えれます)
	void Move(void);
};


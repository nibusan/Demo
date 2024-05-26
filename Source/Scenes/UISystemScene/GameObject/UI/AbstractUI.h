#pragma once
#include <functional>
#include "../../../../Common/Vector2.h"

class AbstractUI {
public:
	// UIの状態
	enum class UI_STATE {
		NORMAL,		// 普通
		HIGHLIGHT	// 強調表示
	};

	AbstractUI(void);
	virtual ~AbstractUI(void);

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Release(void) = 0;

	// 座標
	[[nodiscard]] const Vector2<float>& GetPos(void);
	void SetPos(const Vector2<float>& pos);

	// 角度
	[[nodiscard]] const Vector2<float>& GetRot(void);
	void SetRot(const Vector2<float>& pos);

private:
	Vector2<float> pos_;
	Vector2<float> rot_;
	Vector2<float> scl_;
	std::function<void(void)> onClickCallback_;
	UI_STATE state_;
};
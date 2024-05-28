#pragma once
#include <memory>
#include "../../../Common/Vector2.h"
#include "../../../GameObject/GameObject2D.h"
#include "../../../GameObject/Transform.h"

/// @brief UIの抽象クラスです
/// @brief 2D専用です
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	/// @brief 強調表示するかをセット
	/// @param flag 強調表示するかのフラグ
	void SetHighlighted(bool flag);
protected:
	// 強調表示されてるか
	bool isHighlighted_;

	// 派生クラスで定義
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;

	/// @brief 強調表示されてる時の更新処理 
	virtual void HighlightUpdate(void);
};


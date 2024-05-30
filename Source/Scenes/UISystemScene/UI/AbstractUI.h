#pragma once
#include <memory>
#include <functional>
#include "../../../Common/Vector2.h"
#include "../../../GameObject/GameObject2D.h"
#include "../../../GameObject/Transform.h"

class Graphic;
/// @brief UIの抽象クラスです
/// @note 2DのUIで使うことを前提に設計しているので3Dでは動きません
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;


	/// @brief 強調表示するかをセット
	/// @param flag 強調表示するかのフラグ
	void SetHighlighted(bool flag);

	/// @brief このUIがクリックできるかを返す
	/// @return クリックできるか
	[[nodiscard]] bool IsClickable(void) const;

	/// @brief このUIがクリックできるかをセット
	/// @param isClickable クリックできるか
	void SetClickable(bool isClickable);

	/// @brief クリックされた時に呼び出されるコールバック関数をセット
	/// @param callBack コールバック関数
	void SetOnClickCallBack(const std::function<void(void)>& callBack);

protected:
	// 強調表示されてるか
	bool isHighlighted_;

	// このUIはクリックできるか
	bool isClickable_;

	// クリックされた時に呼び出されるコールバック関数(isClickable_がtrueの時のみ使用できます)
	std::function<void(void)> onClickCallBack_;

	// このUIを描画するためのスクリーン
	//std::unique_ptr<Graphic> renderScreen_;

	void Init_GameObject2D(void) override;
	void Update_GameObject2D(void) override;
	void Release_GameObject2D(void) override;
	
	// 派生クラスで定義
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;

	/// @brief 強調表示されてる時の更新処理 
	virtual void HighlightUpdate(void);

	/// @brief クリックされた時に呼ばれるコールバック関数を呼び出す
	void OnClick(void);
};


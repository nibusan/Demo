#pragma once
#include <memory>
#include <functional>
#include "../../../Common/Vector2.h"
#include "../../../GameObject/GameObject2D.h"
#include "../../../GameObject/Transform.h"
#include "UI_Info.h"

class Graphic;
/// @brief UIの抽象クラスです
/// @note 2DのUIで使うことを前提に設計しているので3Dでは動きません
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;

	/// @brief コンストラクタ
	/// @param canvasSize UIのキャンバスのサイズ
	/// @param originType どこを原点にするか
	AbstractUI(const Vector2<float>& canvasSize, UI::UI_ORIGIN_TYPE originType);

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

	/// @brief 描画用のキャンバスを返す 
	/// @return 描画用のキャンバス
	std::weak_ptr<Graphic> GetRenderCanvas(void);

	/// @brief このUIの種類を返す 
	/// @return UIの種類
	[[nodiscard]] UI::UI_TYPE GetType(void) const;

	/// @brief このUIがどこを原点にしてるかを返す 
	/// @return 原点の種類
	[[nodiscard]] UI::UI_ORIGIN_TYPE GetOriginType(void) const;

	/// @brief UIを描画し終わったキャンバスをスクリーンのどこに描画するかを調整するオフセットを返す
	/// @return オフセット
	Vector2<float> GetCanvasRenderOffset(void) const;
protected:
	// 強調表示されてるか
	bool isHighlighted_;

	// このUIはクリックできるか
	bool isClickable_;

	// クリックされた時に呼び出されるコールバック関数(isClickable_がtrueの時のみ使用できます)
	std::function<void(void)> onClickCallBack_;

	// このUIを描画するためのキャンバス
	std::shared_ptr<Graphic> renderCanvas_;

	// このUIの種類
	UI::UI_TYPE type_;

	// このUIのどこを原点にするか
	UI::UI_ORIGIN_TYPE originType_;

	// 外部から隠蔽するためにpublicにしない
	void Init_GameObject2D(void) override;
	void Update_GameObject2D(void) override;
	void Release_GameObject2D(void) override;
	
	// 派生クラスで定義
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;
	
	/// @brief UIを長押ししている時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickDown(void);

	/// @brief UIを離した時の処理 (isClickable_がtrueの時のみ使用できます)
	virtual void OnClickUp(void);

	/// @brief 強調表示されてる時の更新処理 
	virtual void HighlightUpdate(void);

	/// @brief クリックされた時に呼ばれるコールバック関数を呼び出す
	void OnClick(void);
};


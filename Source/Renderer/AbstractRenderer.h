#pragma once
#include <vector>
#include <memory>
#include "../Common/Handle/Graphic/Graphic.h"

/// @brief 描画機能を提供する抽象クラス
class AbstractRenderer : std::enable_shared_from_this<AbstractRenderer> {
public:
	AbstractRenderer(void);
	virtual ~AbstractRenderer(void) = default ;
	
	/// @brief コンストラクタ
	/// @param useLocalPos 描画する際にローカル座標だけを参照するか
	AbstractRenderer(bool useLocalPos);

	/// @brief 描画開始処理
	virtual void Begin(void) = 0;

	/// @brief 描画処理 
	virtual void Render(void) = 0;

	/// @brief 描画終了処理 
	virtual void End(void) = 0;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) = 0;

	/// @brief 描画する際にローカル座標だけを参照するかを返す 
	/// @return 描画する際にローカル座標だけを参照するか
	bool UseLocalPos(void) const;

	/// @brief 描画する際にローカル座標だけを参照するかをセット
	/// @param flag 描画する際にローカル座標だけを参照するか
	void SetUseLocalPos(bool flag);

	/// @brief 描画対象のオブジェクトが削除されたかを返す 
	/// @return 削除されたか
	virtual bool IsDeleted(void) const = 0;
protected:
	// 元の描画用スクリーンのハンドルID(Begin()でここに退避してEnd()で元に戻す)
	int defaultScreenHadle_;

	// 描画する際にローカル座標だけを参照するか
	bool useLocalPos_;
};
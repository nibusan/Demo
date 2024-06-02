#pragma once
#include "../Common/Handle/Graphic/Graphic.h"

/// @brief 描画機能を提供する抽象クラス
class AbstractRenderer {
public:
	virtual ~AbstractRenderer(void) = default;

	/// @brief 描画開始処理
	virtual void Begin(void) = 0;

	/// @brief 描画処理 
	virtual void Render(void) = 0;

	/// @brief 描画終了処理 
	virtual void End(void) = 0;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) = 0;

protected:
	// 元の描画用スクリーンのハンドルID(Begin()でここに退避してEnd()で元に戻す)
	int defaultScreenHadle_;
};
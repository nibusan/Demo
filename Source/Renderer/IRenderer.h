#pragma once

/// @brief 描画機能だけを提供するインターフェイス
class IRenderer {
public:
	virtual ~IRenderer(void) = default;

	/// @brief 描画処理 
	virtual void Render(void) = 0;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) = 0;
};
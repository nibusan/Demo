#pragma once
#include <memory>
#include "../../../../Renderer/AbstractRenderer.h"

class AbstractUI;
class AbstractUIRenderer : public AbstractRenderer {
public:
	AbstractUIRenderer(void) = default;
	~AbstractUIRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param useLocalPos 描画する際にローカル座標だけを参照するか
	/// @param ui 描画するUI
	AbstractUIRenderer(bool useLocalPos, std::shared_ptr<AbstractUI> ui);

	/// @brief 描画開始処理
	virtual void Begin(void) override;

	/// @brief 描画処理 
	virtual void Render(void) = 0;

	/// @brief 描画終了処理 
	virtual void End(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) = 0;

protected:
	// 描画するUI
	std::shared_ptr<AbstractUI> ui_;

};


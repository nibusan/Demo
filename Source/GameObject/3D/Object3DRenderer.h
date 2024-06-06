//#pragma once
//#include <vector>
//#include <memory>
//#include "../../Renderer/AbstractRenderer.h"
//#include "GameObject3D.h"
//
//class Model;
///// @brief 描画機能を提供する抽象クラス
//class GameObject3DRenderer : AbstractRenderer {
//public:
//	GameObject3DRenderer(void) = default;
//	virtual ~GameObject3DRenderer(void) = default;
//
//	/// @brief 描画開始処理
//	void Begin(void) override;
//
//	/// @brief 描画処理 
//	void Render(void) override;
//
//	/// @brief 描画終了処理 
//	void End(void) override;
//
//	/// @brief 描画処理(デバッグ用) 
//	void DebugRender(void) override;
//
//	/// @brief 描画対象のオブジェクトが削除されたかを返す 
//	/// @return 削除されたか
//	bool IsDeleted(void) const override;
//private:
//	std::shared_ptr<Object3D>
//};
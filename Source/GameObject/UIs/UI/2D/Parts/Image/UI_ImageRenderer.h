#pragma once
#include <memory>
#include "../../../../../../Renderer/IRenderer.h"

class UI_Image;
class UI_ImageRenderer : public IRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_ImageRenderer(std::shared_ptr<UI_Image> uiImage);

	/// @brief 描画処理
	void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;
private:
	// 描画するTextのUI
	std::shared_ptr<UI_Image> uiImage_;

};


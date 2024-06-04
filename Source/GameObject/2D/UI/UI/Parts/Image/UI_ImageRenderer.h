#pragma once
#include <memory>
#include "../../../../../../Renderer/AbstractRenderer.h"
#include "../../AbstractUIRenderer.h"

class UI_Image;
class UI_ImageRenderer : public AbstractUIRenderer {
public:
	UI_ImageRenderer(void) = default;
	~UI_ImageRenderer(void) = default;

	/// @brief コンストラクタ
	/// @param uiText 描画するTextのUI
	UI_ImageRenderer(bool useLocalPos, std::shared_ptr<UI_Image> uiImage);

	/// @brief 描画処理 
	virtual void Render(void) override;

	/// @brief 描画処理(デバッグ用) 
	virtual void DebugRender(void) override;

};


#pragma once
#include "../Renderer/IRenderer.h"

class GameObject2DRenderer : public IRenderer {
public:
	GameObject2DRenderer(void) = default;
	~GameObject2DRenderer(void) noexcept override = default;

	void Render(void);
	virtual void DebugRender(void) = 0;
private:

};

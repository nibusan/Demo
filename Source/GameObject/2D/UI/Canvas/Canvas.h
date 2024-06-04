#pragma once
#include <vector>
#include <memory>

class UILayer;
/// @brief •¡”‚ÌUILayer‚ğŠÇ—‚·‚éƒNƒ‰ƒX
class Canvas {
public:
	Canvas(void) = default;
	~Canvas(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	void AddLayer(std::shared_ptr<UILayer> uiLayer);
private:
	// 
	std::vector<std::shared_ptr<UILayer>> uiLayers_;

};


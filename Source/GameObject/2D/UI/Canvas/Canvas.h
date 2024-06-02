#pragma once
#include <vector>
#include <memory>

class AbstractUILayer;
/// @brief •¡”‚ÌUILayer‚ğŠÇ—‚·‚éƒNƒ‰ƒX
class Canvas {
public:
	Canvas(void) = default;
	~Canvas(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	void AddLayer(std::shared_ptr<AbstractUILayer> uiLayer);
private:
	// 
	std::vector<std::shared_ptr<AbstractUILayer>> uiLayers_;

};


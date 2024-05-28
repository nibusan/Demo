#pragma once
#include <vector>
#include <memory>

class AbstractUILayer;
/// @brief 複数のUILayerを管理するクラス
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


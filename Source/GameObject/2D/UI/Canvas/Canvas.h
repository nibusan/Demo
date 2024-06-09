#pragma once
#include <vector>
#include <memory>

class UILayer;
/// @brief 複数のUILayerを管理するクラス
/// @brief 今回は使用してません
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


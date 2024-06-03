#pragma once
#include <vector>
#include <memory>
#include "../Common/StaticSingleton.h"

class AbstractRenderer;
class RenderManager : public StaticSingleton<RenderManager> {
public:
	~RenderManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(RenderManager);

	void Init(void);
	void Render(void);
	void Release(void);

	/// @brief 2Dのレンダラーを追加
	/// @param renderer2D 2Dレンダラー
	void AddRenderer2D(std::shared_ptr<AbstractRenderer> renderer2D);

	/// @brief 3Dのレンダラーを追加
	/// @param renderer3D 3Dレンダラー
	void AddRenderer3D(std::shared_ptr<AbstractRenderer> renderer3D);

private:
	// 2Dのレンダラーを格納
	std::vector<std::shared_ptr<AbstractRenderer>> renderer2D_;
	
	// 3Dのレンダラーを格納
	std::vector<std::shared_ptr<AbstractRenderer>> renderer3D_;

	RenderManager() = default;

	/// @brief 登録されてる2Dのレンダラーを描画する 
	void Render2D(void);

	/// @brief 登録されてる3Dのレンダラーを描画する 
	void Render3D(void);
};
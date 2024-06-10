#pragma once
#include <vector>
#include <memory>
#include "UILayerInfo.h"

class AbstractUI;
/// @brief 複数のUIのまとまり(ポーズ画面など)を一枚のレイヤーとして扱えるクラス
class UILayer {
public:
	UILayer(void) = default;
	~UILayer(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief 指定されたUILayerを読み込む
	/// @param type UILayerの種類
	void LoadUILayer(UILayerInfo::TYPE type);

	/// @brief UIを追加する
	/// @param ui UI
	void AddUI(const std::shared_ptr<AbstractUI> ui);
private:
	// このレイヤーに登録されたUI
	std::vector<std::shared_ptr<AbstractUI>> uis_;

};
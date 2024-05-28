#pragma once
#include <vector>
#include <memory>

class AbstractUI;
/// @brief 複数のUIのまとまり(ポーズ画面など)を一枚のレイヤーとして扱えるクラス
class AbstractUILayer {
public:
	AbstractUILayer(void) = default;
	~AbstractUILayer(void) = default;

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Release(void) = 0;
private:
	// このレイヤーに登録されたUI
	std::vector<AbstractUI> uis_;

};
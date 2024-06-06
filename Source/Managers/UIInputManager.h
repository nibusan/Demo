#pragma once
#include <memory>
#include "../Common/StaticSingleton.h"

class AbstractUI;
class UIInputManager : public StaticSingleton<UIInputManager> {
public:
	~UIInputManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIInputManager);

	void Init(void);
	void Update(void);

	/// @brief 既にどれかのUIを選択してるかを返す 
	/// @return UIを選択してるか
	bool IsSelected(void) const;

	/// @brief 既にどれかのUIを選択してるかをセットする
	/// @param flag UIを選択してるか
	void SetSelected(bool flag);

	/// @brief 既にどれかのUIをクリックしてるかを返す 
	/// @return UIをクリックしてるか
	bool IsClicked(void) const;

	/// @brief 既にどれかのUIをクリックしてるかをセットする
	/// @param flag UIをクリックしてるか
	void SetClicked(bool flag);

	/// @brief 現在選択しているUIをセット
	/// @param ui UI
	void SetSelectUI(std::weak_ptr<AbstractUI> ui);

	/// @brief 渡されたUIが既にセットされてるUIと同じかを返す
	/// @param ui 比較するUI
	/// @return 同じかどうか
	bool IsSameUI(std::weak_ptr<AbstractUI> ui);
private:
	// 既にどれかのUIを選択してるか
	bool selected_;

	// 既にどれかのUIをクリックしてるか
	bool clicked_;

	// 現在選択しているUI
	std::weak_ptr<AbstractUI> selectUI_;

	UIInputManager(void);
};


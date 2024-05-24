#pragma once

class Item {
public:
	Item(void);
	Item(int id, int count);
	~Item(void) = default;

	/// @brief アイテムIDをセット
	/// @param id アイテムID
	void SetID(int id);

	/// @brief アイテムIDを返す 
	/// @return アイテムID
	int GetID(void) const;

	/// @brief アイテムの個数にを増やす
	/// @param count 増やす数
	void AddCount(int count);

	/// @brief アイテムの個数をセット
	/// @param count 個数
	void SetCount(int count);

	/// @brief アイテムの数を返す 
	/// @return アイテムの個数
	int GetCount(void) const;

private:
	// アイテムID
	int id_;

	// アイテムの個数
	int count_;
};
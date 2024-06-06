#pragma once
#include <memory>

/// @brief インベントリに格納するためのテスト用クラス
class Item {
public:
	// アイテム画像の横の分割数
	static constexpr int ITEM_NUM_X = 8;

	// アイテム画像の縦の分割数
	static constexpr int ITEM_NUM_Y = 8;

	// アイテムIDの最大数
	static constexpr int MAX_ITEM_ID = ITEM_NUM_X * ITEM_NUM_Y - 1;

	Item(void);
	~Item(void) = default;

	/// @brief コンストラクタ
	/// @param id アイテムID
	/// @param count アイテムの個数
	Item(int id, int count);

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

	/// @brief 二つのアイテムが同じかどうかを判定する
	/// @param item1 一つ目のアイテム
	/// @param item2 二つ目のアイテム
	/// @return 同じかどうか
	static bool Equal(const std::shared_ptr<Item>& item1, const std::shared_ptr<Item>& item2);
private:
	// アイテムID
	int id_;

	// アイテムの個数
	int count_;
};
#pragma once
#include <array>
#include <memory>
#include "../Item/Item.h"
//#include "../MenuBase.h"

//class Inventory : public MenuBase {
class Inventory {
public:
	// インベントリで保持できるアイテムスロットの数
	static constexpr int MAX_ITEM_SLOT_COUNT = 9;

private:
	// アイテムスロットを格納した配列
	std::array<std::shared_ptr<Item>, MAX_ITEM_SLOT_COUNT> itemSlot_;

public:
	Inventory(void);
	~Inventory(void) = default;

	void Init(void);
	void Release(void);

	/// @brief アイテムを追加
	/// @param item アイテムのデータ
	void AddItem(std::shared_ptr<Item> item);

	/// @brief 指定されたスロットのアイテムのデータを返す
	/// @param slot スロットのID
	/// @return スロットに入ってるアイテムのデータ
	std::weak_ptr<Item> GetItem(int slot);

	/// @brief 指定されたスロットにアイテムをセット
	/// @param item アイテムのデータ
	/// @param slot	スロットのID
	/// @note 指定されたスロットにアイテムが入っている場合セットしません
	void SetItem(std::shared_ptr<Item> item, int slot);
};

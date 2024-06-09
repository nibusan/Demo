#pragma once
#include <array>
#include <memory>
#include <functional>
#include <algorithm>

class InputManager;
/// @brief インベントリとして使用することに特化したコンテナクラス
/// @brief どのゲームでもすぐに移植して使えるように設計しました
/// @brief このクラスではデータを格納する時はスマートポインタを使います
/// @tparam T アイテムとして格納したいクラス
template <typename T>
class Inventory {
public:
	// インベントリで保持できるアイテムスロットの数
	static constexpr int MAX_ITEM_SLOT_COUNT = 16;

	Inventory(std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare);
	~Inventory(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief アイテムを追加
	/// @param item アイテムのデータ
	void AddItem(const std::shared_ptr<T>& item);

	/// @brief 指定されたスロットのアイテムのデータを返す
	/// @param slot スロットのID
	/// @return スロットに入ってるアイテムのデータ
	std::weak_ptr<T> GetItem(int slot);

	/// @brief 指定されたスロットにアイテムをセット
	/// @brief 指定されたスロットにアイテムが入っている場合セットしません
	/// @param item アイテムのデータ
	/// @param slot	スロットのID
	void SetItem(std::shared_ptr<T> item, int slot);

	/// @brief 指定されたスロットのアイテムを削除する
	/// @param slot	スロットのID
	void DeleteItem(int slot);
private:
	// アイテムスロットを格納した配列
	std::array<std::shared_ptr<T>, MAX_ITEM_SLOT_COUNT> itemSlot_;

	// 同じアイテムか比較するための関数オブジェクト
	std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare_;

	/// @brief 全てのアイテムスロットをクリアする
	void ClearAllItemSlot(void);
};

template<typename T>
Inventory<T>::Inventory(std::function<bool(const std::shared_ptr<T>&, const std::shared_ptr<T>&)> compare) : compare_(compare) {}

template <typename T>
void Inventory<T>::Init(void) {
	// インベントリをリセットする
	ClearAllItemSlot();
}

template<typename T>
inline void Inventory<T>::Update(void) {
	
}

template <typename T>
void Inventory<T>::Release(void) {
	// インベントリをリセットする
	ClearAllItemSlot();
}

template <typename T>
void Inventory<T>::AddItem(const std::shared_ptr<T>& item) {
	// 同じアイテムが入ったスロットを検索
	auto sameItem_Slot = std::find_if(itemSlot_.begin(), itemSlot_.end(), [this, item](const std::shared_ptr<T>& slotItem)->bool {
		// 予めアイテム側で定義しておいた比較する関数を呼び出して
		// 同じアイテムかを判定
		if (slotItem == nullptr) return false;
		return compare_(item, slotItem);
		});
	if (sameItem_Slot != itemSlot_.end()) {
		// もし同じアイテムがあったら追加するアイテムの個数分足す
		(*sameItem_Slot)->AddCount(item->GetCount());
	}
	else {
		// 空のアイテムスロットを検索
		auto emptySlot = std::find(itemSlot_.begin(), itemSlot_.end(), nullptr);
		if (emptySlot != itemSlot_.end()) {
			// もしアイテムスロットが空だったらセットする
			(*emptySlot) = item;
		}
	}
}

template <typename T>
std::weak_ptr<T> Inventory<T>::GetItem(int slot) {
	return itemSlot_[slot];
}

template <typename T>
void Inventory<T>::SetItem(std::shared_ptr<T> item, int slot) {
	// 指定されたスロットにアイテムが無かったらセットする
	if (itemSlot_[slot] == nullptr) itemSlot_[slot] = item;
}

template<typename T>
void Inventory<T>::DeleteItem(int slot) {
	itemSlot_[slot] = nullptr;
}

template<typename T>
void Inventory<T>::ClearAllItemSlot(void) {
	// 全てのアイテムスロットにnullptrを代入して
	// 内部の参照カウンタを0にして自動で解放させる
	for (int i = 0; i < MAX_ITEM_SLOT_COUNT; i++) {
		itemSlot_[i] = nullptr;
	}
}

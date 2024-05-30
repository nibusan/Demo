#pragma once
#include <memory>
#include <vector>
#include "Transform.h"

/// @brief ゲームオブジェクトの基底クラス
class GameObject : public std::enable_shared_from_this<GameObject> {
public:
	GameObject(void);
	virtual ~GameObject(void) = default;
 
	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief このゲームオブジェクトがアクティブかを返す
	/// @return アクティブかどうか
	[[nodiscard]] bool IsActive(void) const;

	/// @brief このゲームオブジェクトがアクティブかをセット
	/// @param flag アクティブかどうか
	void SetActive(bool flag);

	/// @brief 親オブジェクトを返す 
	/// @return 親オブジェクト
	[[nodiscard]] std::weak_ptr<GameObject> GetParent(void) const;
	
	/// @brief 親オブジェクトをセット
	/// @param parent 親オブジェクト
	/// @note 2Dと3Dで計算が変わるので必ず派生クラスで実装すること
	virtual void SetParent(std::weak_ptr<GameObject> parent) = 0;

	/// @brief 子オブジェクトを格納した配列を返す 
	/// @return 子オブジェクトを格納した配列
	[[nodiscard]] const std::vector<std::shared_ptr<GameObject>> GetChilds(void) const;
	
	/// @brief 子オブジェクトを追加する
	/// @param child 子オブジェクト
	/// @note 2Dと3Dで計算が変わるので必ず派生クラスで実装すること
	virtual void AddChild(std::shared_ptr<GameObject> child) = 0;

protected:
	// アクティブかどうか
	bool isActive_;

	// 親オブジェクト
	std::weak_ptr<GameObject> parent_;
	
	// 子オブジェクトを格納した可変長配列
	std::vector<std::shared_ptr<GameObject>> childs_;

	// 派生クラスで定義する関数
	virtual void Init_GameObject(void) = 0;
	virtual void Update_GameObject(void) = 0;
	virtual void Release_GameObject(void) = 0;
};

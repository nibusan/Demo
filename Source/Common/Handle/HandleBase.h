#pragma once

/// @brief 
class HandleBase {
public:
	HandleBase(void);
	virtual ~HandleBase(void) = default;

	/// @brief ハンドルIDを返す
	/// @return ハンドルID
	[[nodiscard]] int GetHandle(void) const;

	/// @brief ハンドルIDをセット
	/// @param handle ハンドルID
	void SetHandle(int handle);

	/// @brief デストラクタが呼ばれた際に自動的にハンドルを削除するかを返す
	/// @return 削除するかのフラグ
	[[nodiscard]] bool IsAutoDeleteHandle(void) const;

	/// @brief デストラクタが呼ばれた際に自動的にハンドルを削除するかをセット
	/// @param flag 削除するかのフラグ
	void SetIsAutoDeleteHandle(bool flag);

protected:
	//ハンドルID
	int handle_;

	//デストラクタが呼ばれたときにハンドルを破棄するかを管理(true:自動破棄)
	bool isAutoDeleteHandle_;
};

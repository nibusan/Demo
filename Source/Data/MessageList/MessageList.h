#pragma once
#include <unordered_map>
#include <string>
#include "../../Common/StaticSingleton.h"

class MessageList : public StaticSingleton<MessageList> {
public:
	~MessageList(void);
	THIS_CLASS_IS_STATIC_SINGLETON(MessageList);

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(void);

	/// @brief 指定されたメッセージの文字列を返す
	/// @param id メッセージID
	/// @return メッセージの文字列
	[[nodiscard]] const std::wstring& GetMessage_(int id) const;

private:
	// 読み込んだメッセージを管理(キー:ID, 値:読み込んだテキスト(wstring))
	std::unordered_map<int, std::wstring> messageTable_;

	MessageList(void);
};
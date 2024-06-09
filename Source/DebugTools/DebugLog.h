#pragma once
#include <vector>
#include <string>
#include "../Common/StaticSingleton.h"

class DebugLog : public StaticSingleton<DebugLog> {
public:
	/// @brief ログのデータ
	/// @param displayTime 表示する残り時間
	/// @param log ログのテキスト
	/// @param logColor ログのテキストの色
	struct LogData {
		float displayTime;
		std::string log;
		unsigned int logColor;
	};

	~DebugLog(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(DebugLog);

	void Init(void);
	void Update(void);

	/// @brief ログを追加
	/// @param log ログのデータ
	void AddLog(const LogData& log);

	/// @brief 全てのログが格納された配列を返す
	/// @return ログが格納された配列
	const std::vector<LogData>& GetLogs(void) const;
private:
	// ログを管理
	std::vector<LogData> logs_;

	DebugLog(void) = default;
};
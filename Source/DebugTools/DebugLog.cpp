#include <algorithm>
#include "../Application.h"
#include "DebugLog.h"

void DebugLog::Init(void) {
	logs_.clear();
}

void DebugLog::Update(void) {
	for (auto& log : logs_) {
		// 各ログの表示時間を減らす
		log.displayTime -= Application::DELTA_TIME;
	}

	// 表示時間が0秒以下になった要素を削除する
	auto removeItr = std::remove_if(logs_.begin(), logs_.end(), [](const LogData& log)->bool { return log.displayTime <= 0.0f; });
	logs_.erase(removeItr, logs_.end());
}

void DebugLog::AddLog(const LogData& log) {
	logs_.emplace_back(log);
}

const std::vector<DebugLog::LogData>& DebugLog::GetLogs(void) const {
	return logs_;
}
#include <algorithm>
#include "../Application.h"
#include "DebugLog.h"

void DebugLog::Init(void) {
	logs_.clear();
}

void DebugLog::Update(void) {
	for (auto& log : logs_) {
		// �e���O�̕\�����Ԃ����炷
		log.displayTime -= Application::DELTA_TIME;
	}

	// �\�����Ԃ�0�b�ȉ��ɂȂ����v�f���폜����
	auto removeItr = std::remove_if(logs_.begin(), logs_.end(), [](const LogData& log)->bool { return log.displayTime <= 0.0f; });
	logs_.erase(removeItr, logs_.end());
}

void DebugLog::AddLog(const LogData& log) {
	logs_.emplace_back(log);
}

const std::vector<DebugLog::LogData>& DebugLog::GetLogs(void) const {
	return logs_;
}
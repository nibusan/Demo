#pragma once
#include <vector>
#include <string>
#include "../Common/StaticSingleton.h"

class DebugLog : public StaticSingleton<DebugLog> {
public:
	/// @brief ���O�̃f�[�^
	/// @param displayTime �\������c�莞��
	/// @param log ���O�̃e�L�X�g
	/// @param logColor ���O�̃e�L�X�g�̐F
	struct LogData {
		float displayTime;
		std::string log;
		unsigned int logColor;
	};

	~DebugLog(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(DebugLog);

	void Init(void);
	void Update(void);

	/// @brief ���O��ǉ�
	/// @param log ���O�̃f�[�^
	void AddLog(const LogData& log);

	/// @brief �S�Ẵ��O���i�[���ꂽ�z���Ԃ�
	/// @return ���O���i�[���ꂽ�z��
	const std::vector<LogData>& GetLogs(void) const;
private:
	// ���O���Ǘ�
	std::vector<LogData> logs_;

	DebugLog(void) = default;
};
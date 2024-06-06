#pragma once
#include <unordered_map>
#include <string>
#include "../../Common/StaticSingleton.h"

class MessageList : public StaticSingleton<MessageList> {
public:
	~MessageList(void);
	THIS_CLASS_IS_STATIC_SINGLETON(MessageList);

	/// <summary>
	/// ������
	/// </summary>
	void Init(void);

	/// @brief �w�肳�ꂽ���b�Z�[�W�̕������Ԃ�
	/// @param id ���b�Z�[�WID
	/// @return ���b�Z�[�W�̕�����
	[[nodiscard]] const std::wstring& GetMessage_(int id) const;

private:
	// �ǂݍ��񂾃��b�Z�[�W���Ǘ�(�L�[:ID, �l:�ǂݍ��񂾃e�L�X�g(wstring))
	std::unordered_map<int, std::wstring> messageTable_;

	MessageList(void);
};
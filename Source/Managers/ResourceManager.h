#pragma once
#include <memory>
#include <string>
#include "../Common/StaticSingleton.h"

class HandleBase;
class ResourceManager : public StaticSingleton<ResourceManager> {
public:
	~ResourceManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(ResourceManager);

	void Init(void);

	/// @brief �o�^����Ă��郊�\�[�X�t�@�C���̃f�[�^��Ԃ�
	/// @param key �擾���������\�[�X�t�@�C���̃L�[
	/// @return �L�[�ɑΉ��������\�[�X�t�@�C���̃f�[�^
	std::weak_ptr<HandleBase> GetResource(const std::string& key);

private:
	ResourceManager(void) = default;
};


#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <filesystem>
#include "../Common/StaticSingleton.h"
#include "../Common/Handle/HandleBase.h"
#include "Resource.h"

class ResourceManager : public StaticSingleton<ResourceManager> {
public:
	// �A�Z�b�g(���\�[�X�t�@�C��)���i�[����t�H���_�ւ̃x�[�X�̃p�X
	static const std::filesystem::path BASE_ASSETS_PATH;

	// ���\�[�X���X�g��json�t�@�C���ւ̃p�X
	static const std::filesystem::path RESOURCE_LIST_PATH;

	~ResourceManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(ResourceManager);

	void Init(void);

	/// @brief �o�^����Ă��郊�\�[�X�t�@�C���̃f�[�^��Ԃ�
	/// @param key �擾���������\�[�X�t�@�C���̃L�[
	/// @return �L�[�ɑΉ��������\�[�X�t�@�C���̃f�[�^
	std::weak_ptr<HandleBase> GetResource(const std::string& key);

private:
	/// @brief ���\�[�X�t�@�C�����Ǘ����邽�߂̃f�[�^
	/// @param key ���\�[�X�t�@�C���̃L�[
	/// @param filePath ���\�[�X�t�@�C���ւ̃p�X
	/// @param fileName ���\�[�X�t�@�C���̖̂��O
	/// @param extension ���\�[�X�t�@�C���̊g���q
	struct RESOURCE_FILE_INFO {
		std::filesystem::path filePath;
		std::string fileName;
		std::string extension;
	};

	// ���\�[�X�t�@�C�����Ǘ�����A�z�z��(�L�[ : ���\�[�X�t�@�C���̃L�[, �l : ���\�[�X�t�@�C���̃f�[�^)
	std::unordered_map<std::string, RESOURCE_FILE_INFO> resourceFileInfoList_;

	ResourceManager(void) = default;
};


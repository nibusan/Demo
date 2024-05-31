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
	// アセット(リソースファイル)を格納するフォルダへのベースのパス
	static const std::filesystem::path BASE_ASSETS_PATH;

	// リソースリストのjsonファイルへのパス
	static const std::filesystem::path RESOURCE_LIST_PATH;

	~ResourceManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(ResourceManager);

	void Init(void);

	/// @brief 登録されているリソースファイルのデータを返す
	/// @param key 取得したいリソースファイルのキー
	/// @return キーに対応したリソースファイルのデータ
	std::weak_ptr<HandleBase> GetResource(const std::string& key);

private:
	/// @brief リソースファイルを管理するためのデータ
	/// @param key リソースファイルのキー
	/// @param filePath リソースファイルへのパス
	/// @param fileName リソースファイルのの名前
	/// @param extension リソースファイルの拡張子
	struct RESOURCE_FILE_INFO {
		std::filesystem::path filePath;
		std::string fileName;
		std::string extension;
	};

	// リソースファイルを管理する連想配列(キー : リソースファイルのキー, 値 : リソースファイルのデータ)
	std::unordered_map<std::string, RESOURCE_FILE_INFO> resourceFileInfoList_;

	ResourceManager(void) = default;
};


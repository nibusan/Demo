#include <array>
#include "ResourceManager.h"
#include "JsonReader.h"

const std::filesystem::path BASE_PATH = "Assets/";
const std::filesystem::path RESOURCE_LIST_PATH =  BASE_PATH / "ResourceList/ResourceList.json";

void ResourceManager::Init(void) {
	// リソースファイルリスト(json)の読み込み
	const auto& resourceList = JsonReader::GetInstance().Parse("Assets/ResourceList/ResourceList.json");

	// jsonの各リソースファイルの種類を指すタグ(jsonのキー)
	const std::array<std::string, static_cast<int>(Resource::RESOURCE_FILE_TYPE::MAX)> ResourceFileTag = {
		"Image",
		"Sound",
		"Model",
		"PixelShader",
		"VertexShader"
	};
	
	// 各リソースファイルの情報を登録
	for (int i = 0; i < static_cast<int>(Resource::RESOURCE_FILE_TYPE::MAX); i++) {
		for (const auto& resourceFile : resourceList["ResourceList"][ResourceFileTag[i]]) {
			RESOURCE_FILE_INFO info;
			info.filePath = 
				BASE_PATH / static_cast<std::filesystem::path>(static_cast<std::string>(resourceFile["FilePath"]));
			info.fileName = resourceFile["FileName"];
			info.extension = resourceFile["Extension"];
			resourceFileInfoList_[resourceFile["Key"]] = info;
		}
	}

}

std::weak_ptr<HandleBase> ResourceManager::GetResource(const std::string& key) {
    return std::weak_ptr<HandleBase>();
}

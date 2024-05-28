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

	/// @brief 登録されているリソースファイルのデータを返す
	/// @param key 取得したいリソースファイルのキー
	/// @return キーに対応したリソースファイルのデータ
	std::weak_ptr<HandleBase> GetResource(const std::string& key);

private:
	ResourceManager(void) = default;
};


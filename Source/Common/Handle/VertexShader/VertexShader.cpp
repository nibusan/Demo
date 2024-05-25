#include <DxLib.h>
#include "VertexShader.h"

VertexShader::VertexShader(void) {

}

VertexShader::VertexShader(const std::filesystem::path& path) {
	handle_ = LoadVertexShader(path.string().c_str());
}

VertexShader::VertexShader(int handle) {
	handle_ = handle;

	std::string className = std::string(typeid(this).name());
	className = className.substr(0, className.find("*"));
	SceneManager::GetInstance().CreateDebugText(
		className,
		className + "のコンストラクタが呼ばれた\n"
	);
}

VertexShader::~VertexShader(void) {
	std::string className = std::string(typeid(this).name());
	className = className.substr(0, className.find("*"));
	SceneManager::GetInstance().CreateDebugText(
		className,
		className + "のデストラクタが呼ばれた\n"
	);
}

void VertexShader::SetUseShader(void) {
	SetUseVertexShader(GetHandle());
}

#pragma once
#include <memory>
#include <filesystem>
#include <string>
#include <DxLib.h>
#include "../../Vector2.h"
#include "../HandleBase.h"

class VertexShader : public HandleBase {
public:
	VertexShader(void) = delete;
	VertexShader(const std::filesystem::path& path);
	VertexShader(int handle);
	~VertexShader(void);
private:
	
};

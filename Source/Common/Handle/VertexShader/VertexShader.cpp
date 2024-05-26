#include <DxLib.h>
#include "VertexShader.h"

VertexShader::VertexShader(const std::filesystem::path& path) {
	handle_ = LoadVertexShader(path.string().c_str());
}

VertexShader::VertexShader(int handle) {
	handle_ = handle;
}

VertexShader::~VertexShader(void) {
	if (IsAutoDeleteHandle()) {
		DeleteShader(handle_);
	}
}
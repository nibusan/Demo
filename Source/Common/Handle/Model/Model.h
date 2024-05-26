#pragma once
#include <filesystem>
#include <string>
#include <DxLib.h>
#include "../HandleBase.h"
#include "../VertexShader/VertexShader.h"
#include "../PixelShader/PixelShader.h"

class VertexShader;
class PixelShader;
class Model : public HandleBase
{
public:
	Model(void);
	Model(const std::filesystem::path& path);
	Model(int handle);

	~Model(void) override;

	/// @brief MV1���f����`��
	/// @param pos ���W
	/// @param localPos ���[�J�����W
	/// @param rot �p�x
	/// @param localRot ���[�J���p�x(���O�Ԉ���Ă邩��)
	/// @param scl �X�P�[���l
	/// @param vs ���_�V�F�[�_�[
	/// @param ps �s�N�Z���V�F�[�_�[
	void Draw(
		VECTOR pos, 
		VECTOR localPos, 
		VECTOR rot, 
		VECTOR localRot, 
		VECTOR scl, 
		Shared_VertexShader vs,
		Shared_PixelShader ps
	);
};

using Unique_Model = std::unique_ptr<Model>;
using Shared_Model = std::shared_ptr<Model>;
using Weak_Model = std::weak_ptr<Model>;
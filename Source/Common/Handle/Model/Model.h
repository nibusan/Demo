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

	/// @brief MV1モデルを描画
	/// @param pos 座標
	/// @param localPos ローカル座標
	/// @param rot 角度
	/// @param localRot ローカル角度(名前間違ってるかも)
	/// @param scl スケール値
	/// @param vs 頂点シェーダー
	/// @param ps ピクセルシェーダー
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
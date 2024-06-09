#pragma once
#include <concepts>
#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>
#include "../../Vector2.h"
#include "../HandleBase.h"

class PixelShader;
class Graphic : public HandleBase
{

public:
	Graphic(void);
	Graphic(const std::filesystem::path& path);
	Graphic(int handle);

	~Graphic(void) override;

	// �`��n
	void Draw(const Vector2<float>& pos, bool isCenterDraw, const std::shared_ptr<PixelShader>& ps);
	void Draw(const Vector2<float>& pos, bool isCenterDraw, int divX, int divY, int numX, int numY, const std::shared_ptr<PixelShader>& ps);
	void Draw(const Vector2<float>& pos, float scale, float angle, int divX, int divY, int numX, int numY, const std::shared_ptr<PixelShader>& ps);
	void Draw(const Vector2<float>& pos1, const Vector2<float>& pos2, const std::shared_ptr<PixelShader>& ps);
	void Draw(const Vector2<float>& pos1, const Vector2<float>& pos2, const Vector2<float>& pos3, const std::shared_ptr<PixelShader>& ps);
	void Draw(const Vector2<float>& pos, float scale, float angle, const std::shared_ptr<PixelShader>& ps);

	[[nodiscard]] const Vector2<int>& GetSize(void) const;

private:
	Vector2<int> size_;	// �T�C�Y
	int beforeShaderScreen_;	// �V�F�[�_�[��K�p����O�̏�Ԃ�`�悷��X�N���[��
	int afterShaderScreen_;		// �V�F�[�_�[��K�p������̏�Ԃ�`�悷��X�N���[��
};
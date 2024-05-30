#pragma once
#include <filesystem>
#include <memory> 
#include <string>
#include "../../Vector2.h"
#include "../HandleBase.h"

class Font final : public HandleBase {
private:
	std::filesystem::path path_;
	std::string name_;
	int size_;

public:
	Font(void);
	Font(const std::filesystem::path& path, std::string name, int fontSize);
	Font(std::string name, int size);

	~Font(void) override;

	[[nodiscard]] int GetFontSize(void) const;
	[[nodiscard]] std::string GetFontName(void) const;

	/// @brief ���̃t�H���g�ŕ�����`�悷��
	/// @param pos �`�悷����W
	/// @param text �`�悷��e�L�X�g
	/// @param textColor �e�L�X�g�̐F
	void Draw(const Vector2<float>& pos, const std::string& text, unsigned int textColor);

};

using Unique_Font = std::unique_ptr<Font>;
using Shared_Font = std::shared_ptr<Font>;
using Weak_Font = std::weak_ptr<Font>;
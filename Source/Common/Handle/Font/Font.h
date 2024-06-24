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
	Font(void) = delete;
	Font(const std::filesystem::path& path, std::string name, int fontSize);
	Font(std::string name, int size);

	~Font(void) override;

	[[nodiscard]] int GetFontSize(void) const;
	[[nodiscard]] std::string GetFontName(void) const;

	/// @brief このフォントで文字を描画する
	/// @param pos 描画する座標
	/// @param text 描画するテキスト
	/// @param textColor テキストの色
	void Draw(const Vector2<float>& pos, const std::string& text, unsigned int textColor);

};
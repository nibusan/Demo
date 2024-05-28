#include <fstream>
#include <istream>
#include <sstream>
#include <filesystem>
#include "JsonReader.h"

nlohmann::json JsonReader::Parse(const std::filesystem::path& path) {
	std::ifstream ifs(path.string());
	nlohmann::json parcedJson_;
	ifs >> parcedJson_;
	return parcedJson_;
}

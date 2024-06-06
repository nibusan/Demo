#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "../../Utility/Utility.h"
#include "../../Managers/ResourceManager.h"
#include "MessageList.h"

MessageList::MessageList(void) {

}

MessageList::~MessageList(void) {

}


void MessageList::Init(void) {
	std::string path = ResourceManager::BASE_ASSETS_PATH.string() + "MessageList/MessageList.txt";
	std::ifstream ifs(path);
	std::string buf;
	while (std::getline(ifs, buf)) {
		messageTable_[
			std::stoi(buf.substr(0, buf.find(":")))
		] = 
			Utility::StringToWString(buf.substr(buf.find(":") + 1, buf.length() - buf.find(":")));
	}
}

const std::wstring& MessageList::GetMessage_(int id) const {
	return messageTable_.at(id);
}
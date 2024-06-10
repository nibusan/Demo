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
	// メッセージリストの読み込み
	std::string path = ResourceManager::BASE_ASSETS_PATH.string() + "MessageList/MessageList.txt";
	std::ifstream ifs(path);
	std::string buf;
	
	// 行ごとに分割して読み込む
	while (std::getline(ifs, buf)) {
		// IDとメッセージの部分で分けて格納する
		messageTable_[
			std::stoi(buf.substr(0, buf.find(":")))
		] = 
			Utility::StringToWString(buf.substr(buf.find(":") + 1, buf.length() - buf.find(":")));
	}
}

const std::wstring& MessageList::GetMessage_(int id) const {
	return messageTable_.at(id);
}

void MessageList::Release(void) {
	messageTable_.clear();
}

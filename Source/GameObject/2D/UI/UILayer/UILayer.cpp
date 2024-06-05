#include "UILayer.h"
#include "../../../../Managers/ResourceManager.h"
#include "../../../../Managers/RenderManager.h"
#include "../../../../Managers/JsonReader.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "../UI/UI_Info.h"
#include "../UI/UIFactory.h"
#include "../UI/AbstractUI.h"

#include "UILayer.h"

void UILayer::Init(void) {
	for (const auto& ui : uis_) {
		ui->Init();
	}
}

void UILayer::Update(void) {
	for (const auto& ui : uis_) {
		ui->Update();
	}
}

void UILayer::Release(void) {
	for (const auto& ui : uis_) {
		ui->Release();
	}
}

void UILayer::LoadUILayer(UILayerInfo::TYPE type) {
	// リソースファイルリスト(json)の読み込み
	const auto uiLayerListJson = JsonReader::GetInstance().Parse("Assets/UILayerList/UILayerList.json");
	
	std::string uiLayerPath = uiLayerListJson["UILayerListPath"][static_cast<int>(type)];
	const auto uiLayerJson = JsonReader::GetInstance().Parse("Assets/" + uiLayerPath);

	auto& uiFactory = UIFactory::GetInstance();

	for (const auto& ui : uiLayerJson["UIs"]) {
		uis_.emplace_back(uiFactory.CreateUI(ui, true, false));
	}
}

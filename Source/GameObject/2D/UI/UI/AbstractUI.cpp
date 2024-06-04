#include "AbstractUI.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../Managers/PixelShaderEventManager.h"

AbstractUI::AbstractUI(void) : 
isHighlighted_(false),
renderCanvas_(nullptr),
type_(UI::UI_TYPE::NONE),
originType_(UI::UI_ORIGIN_TYPE::CENTER_CENTER),
isClickable_(false),
onClickCallBack_(nullptr),
usingPixelShaderEventID_(-1) {}

AbstractUI::AbstractUI(
	const Vector2<float>& canvasSize, 
	UI::UI_ORIGIN_TYPE originType,
	bool isClickable,
	const std::function<void(void)> onClickCallBack,
	std::weak_ptr<PixelShader> usingPixelShader,
	int usingPixelShaderEventID
) : 
isHighlighted_(false),
renderCanvas_(std::make_unique<Graphic>(MakeScreen(static_cast<int>(canvasSize.x), static_cast<int>(canvasSize.y), true))),
type_(UI::UI_TYPE::NONE),
originType_(originType),
isClickable_(isClickable),
onClickCallBack_(onClickCallBack),
usingPixelShader_(usingPixelShader),
usingPixelShaderEventID_(usingPixelShaderEventID) {}

void AbstractUI::Init_GameObject2D(void) {
	Init_UI();
	SetHighlighted(false);

}

void AbstractUI::Update_GameObject2D(void) {
	Update_UI();
	PixelShaderEventManager::GetInstance().StartUpdateEvent(usingPixelShaderEventID_);
}

void AbstractUI::Release_GameObject2D(void) {
	Release_UI();
}

void AbstractUI::SetHighlighted(bool flag) {
	isHighlighted_ = flag;
}

bool AbstractUI::IsClickable(void) const {
	return isClickable_;
}

void AbstractUI::SetClickable(bool isClickable) {
	isClickable_ = isClickable;
}

void AbstractUI::SetOnClickCallBack(const std::function<void(void)>& callBack) {
	onClickCallBack_ = callBack;
}

void AbstractUI::OnClickDown(void) {}

void AbstractUI::OnClickUp(void) {}

void AbstractUI::HighlightUpdate(void) {}

void AbstractUI::OnClick(void) {
	// コールバック関数がセットされてる時だけ呼び出す
	if (onClickCallBack_ == nullptr) return;
	onClickCallBack_();
}

Vector2<float> AbstractUI::GetCanvasRenderOffset(void) const {
	// 描画用キャンバスのサイズを取得
	const auto& canvasSize = renderCanvas_->GetSize().ToVector2f();
	
	// 計算結果格納用
	Vector2<float> ret = {};

	// 原点の種類によってオフセットを計算する
	switch (originType_) {
	case UI::UI_ORIGIN_TYPE::UP_LEFT: {
		ret = canvasSize / 2.0f;
		break;
	}
	case UI::UI_ORIGIN_TYPE::UP_CENTER: {
		ret = {
			0.0f,
			canvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::UP_RIGHT: {
		ret = {
			-canvasSize.x / 2.0f,
			canvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_LEFT: {
		ret = {
			canvasSize.x / 2.0f,
			0.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_CENTER: {
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_RIGHT: {
		ret = {
			-canvasSize.x / 2.0f,
			0.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_LEFT: {
		ret = {
			canvasSize.x / 2.0f,
			-canvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_CENTER: {
		ret = {
			0.0f,
			-canvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_RIGHT: {
		ret = {
			-canvasSize.x / 2.0f,
			-canvasSize.y / 2.0f
		};
		break;
	}
	default:
		break;
	}
	return ret;
}

std::weak_ptr<PixelShader> AbstractUI::GetUsingPixelShader(void) const {
	return usingPixelShader_;
}

int AbstractUI::GetUsingPixelShaderEventID(void) const {
	return usingPixelShaderEventID_;
}

void AbstractUI::SetUsingPixelShaderEventID(int eventID) {
	usingPixelShaderEventID_ = eventID;
}

std::weak_ptr<Graphic> AbstractUI::GetRenderCanvas(void) {
	return renderCanvas_;
}

UI::UI_TYPE AbstractUI::GetType(void) const {
    return type_;
}

UI::UI_ORIGIN_TYPE AbstractUI::GetOriginType(void) const {
    return originType_;
}
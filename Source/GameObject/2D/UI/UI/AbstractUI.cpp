#include "AbstractUI.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"

AbstractUI::AbstractUI(void) : 
isHighlighted_(false),
isClickable_(false),
onClickCallBack_(nullptr),
renderCanvas_(nullptr),
type_(UI::UI_TYPE::NONE),
originType_(UI::UI_ORIGIN_TYPE::CENTER_CENTER),
isChildUIClipped_(false){}

AbstractUI::AbstractUI(const Vector2<float>& canvasSize, UI::UI_ORIGIN_TYPE originType, bool isChildUIClipped) : 
isHighlighted_(false),
isClickable_(false),
onClickCallBack_(nullptr),
renderCanvas_(std::make_unique<Graphic>(MakeScreen(static_cast<int>(canvasSize.x), static_cast<int>(canvasSize.y), true))),
type_(UI::UI_TYPE::NONE),
originType_(originType),
isChildUIClipped_(isChildUIClipped){}

void AbstractUI::Init_GameObject2D(void) {
	Init_UI();
	SetHighlighted(false);
}

void AbstractUI::Update_GameObject2D(void) {
	Update_UI();
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
	// �R�[���o�b�N�֐����Z�b�g����Ă鎞�����Ăяo��
	if (onClickCallBack_ == nullptr) return;
	onClickCallBack_();
}

Vector2<float> AbstractUI::GetCanvasRenderOffset(void) const {
	// �`��p�L�����o�X�̃T�C�Y���擾
	const auto& canvasSize = renderCanvas_->GetSize().ToVector2f();
	
	// �v�Z���ʊi�[�p
	Vector2<float> ret = {};

	// ���_�̎�ނɂ���ăI�t�Z�b�g���v�Z����
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

bool AbstractUI::IsChildUIClipped(void) const {
	return isChildUIClipped_;
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
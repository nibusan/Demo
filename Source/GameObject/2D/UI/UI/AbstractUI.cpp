#include "AbstractUI.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../Common/Handle/Sound/Sound.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "../../../../Managers/InputManager.h"

AbstractUI::AbstractUI(void) : 
isHighlighted_(false),
preIsHighlighted_(false),
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
preIsHighlighted_(false),
renderCanvas_(std::make_unique<Graphic>(MakeScreen(static_cast<int>(canvasSize.x), static_cast<int>(canvasSize.y), true))),
type_(UI::UI_TYPE::NONE),
originType_(originType),
isClickable_(isClickable),
onClickCallBack_(onClickCallBack),
usingPixelShader_(usingPixelShader),
usingPixelShaderEventID_(usingPixelShaderEventID) {
	// �f�X�g���N�^���Ă΂ꂽ�玩���ŉ������悤�ɂ���
	renderCanvas_->SetIsAutoDeleteHandle(true);
}

bool AbstractUI::IsHighlighted(void) const {
	return isHighlighted_;
}

void AbstractUI::Init_GameObject2D(void) {
	Init_UI();
	SetHighlighted(false);
	PixelShaderEventManager::GetInstance().StartUpdateEvent(usingPixelShaderEventID_);
}

void AbstractUI::Update_GameObject2D(void) {
	// �O��̏�Ԃ�ޔ�
	preIsHighlighted_ = isHighlighted_;

	auto& inputManager = InputManager::GetInstance();

	// �����N���b�N�ł��ĂȂ����R���C�_�[����������Ă���UI��I�����Ă邩�̏���������
	if (isClickable_) {
		if (collider_ != nullptr) {
			collider_->SetCenterPos(transform_.currentPos_ + (renderCanvas_->GetSize().ToVector2f() / 2.0f));
			if (collider_->IsContains(inputManager.GetMousePos().ToVector2f())) {
				isHighlighted_ = true;
			}
			else {
				isHighlighted_ = false;
			}
		}
	}

	// �J�[�\�������������ɔ�������g���K�[�Ō��ʉ���炷�����肷��
	if ((!preIsHighlighted_ && isHighlighted_) && !selectSound_.expired()) selectSound_.lock()->Play(false);

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
	const auto scaleCanvasSize = canvasSize * transform_.currentScl_;
	
	// �v�Z���ʊi�[�p
	Vector2<float> ret = {};

	// ���_�̎�ނɂ���ăI�t�Z�b�g���v�Z����
	switch (originType_) {
	case UI::UI_ORIGIN_TYPE::UP_LEFT: {
		ret = scaleCanvasSize / 2.0f;
		break;
	}
	case UI::UI_ORIGIN_TYPE::UP_CENTER: {
		ret = {
			0.0f,
			scaleCanvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::UP_RIGHT: {
		ret = {
			-scaleCanvasSize.x / 2.0f,
			scaleCanvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_LEFT: {
		ret = {
			scaleCanvasSize.x / 2.0f,
			0.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_CENTER: {
		break;
	}
	case UI::UI_ORIGIN_TYPE::CENTER_RIGHT: {
		ret = {
			-scaleCanvasSize.x / 2.0f,
			0.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_LEFT: {
		ret = {
			scaleCanvasSize.x / 2.0f,
			-scaleCanvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_CENTER: {
		ret = {
			0.0f,
			-scaleCanvasSize.y / 2.0f
		};
		break;
	}
	case UI::UI_ORIGIN_TYPE::DOWN_RIGHT: {
		ret = {
			-scaleCanvasSize.x / 2.0f,
			-scaleCanvasSize.y / 2.0f
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

void AbstractUI::SetSelectSound(std::weak_ptr<Sound> sound) { 
	selectSound_ = sound;
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
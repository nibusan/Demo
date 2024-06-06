#include "AbstractUI.h"
#include "../../../../Common/Handle/Graphic/Graphic.h"
#include "../../../../Common/Handle/Sound/Sound.h"
#include "../../../../Managers/PixelShaderEventManager.h"
#include "../../../../Managers/InputManager.h"
#include "../../../../Managers/UIInputManager.h"
#include "../../../../Managers/SceneManager.h"
//#include "../../../../Debug/DebugLog.h"

AbstractUI::AbstractUI(void) : 
isHighlighted_(false),
preIsHighlighted_(false),
renderCanvas_(nullptr),
type_(UI::UI_TYPE::NONE),
originType_(UI::UI_ORIGIN_TYPE::CENTER_CENTER),
isClickable_(false),
onClickCallBack_(nullptr),
usingPixelShaderEventID_(-1),
isSelect_(false) {}

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
usingPixelShaderEventID_(usingPixelShaderEventID),
isSelect_(false) {
	// �f�X�g���N�^���Ă΂ꂽ�玩���ŉ������悤�ɂ���
	renderCanvas_->SetIsAutoDeleteHandle(true);
}

bool AbstractUI::IsHighlighted(void) const {
	return isHighlighted_;
}

void AbstractUI::Init_GameObject2D(void) {
	Init_UI();
	SetHighlighted(false);
	isSelect_ = false;
	PixelShaderEventManager::GetInstance().StartUpdateEvent(usingPixelShaderEventID_);
}

void AbstractUI::Update_GameObject2D(void) {
	// �O��̏�Ԃ�ޔ�
	preIsHighlighted_ = isHighlighted_;

	// �I����Ԃ����Z�b�g����
	isSelect_ = false;

	// �R���C�_�[�̈ʒu�X�V
	if (collider_ != nullptr) {
		if(parent_.expired()) collider_->SetCenterPos(transform_.currentPos_ + (renderCanvas_->GetSize().ToVector2f() / 2.0f));
		else collider_->SetCenterPos(transform_.currentPos_);
	}

	// ���͌��m�p
	auto& inputManager = InputManager::GetInstance();
	auto& uiInputManager = UIInputManager::GetInstance();

	// �����N���b�N�ł��ĂȂ����R���C�_�[����������Ă���UI��I�����Ă邩�̏���������
	if (!isClickable_) {
		Update_UI();
		return;
	};

	if (collider_ != nullptr) {
		// �}�E�X�J�[�\����UI�̃R���C�_�[���ɓ����Ă�����
		if (collider_->IsContains(inputManager.GetMousePos().ToVector2f())) {
			// �I����Ԃɂ��đ���UI��I���ł��Ȃ��悤�ɂ���
			if (!uiInputManager.IsSelected()) {

				isSelect_ = true;
				uiInputManager.SetSelectUI(std::dynamic_pointer_cast<AbstractUI>(weak_from_this().lock()));

			}

			// ���ɑI�����Ă���UI�����g�Ƃ͈ႤUI�������狭���\������߂�
			if (!uiInputManager.IsSameUI(std::dynamic_pointer_cast<AbstractUI>(weak_from_this().lock()))) {
				isSelect_ = false;
				isHighlighted_ = false;
				Update_UI();
				return;
			}

			// �����\����Ԃɂ���
			isHighlighted_ = true;

			// �����ō��N���b�N������ݒ肳�ꂽ�R�[���o�b�N�֐����Ă�
			if (!uiInputManager.IsClicked()) {
				if (inputManager.IsTrgMouseLeft()) {
					OnClick();
					uiInputManager.SetClicked(true);
					//DebugLog::GetInstance().AddLog({ 5.0f, "UI Clicked", 0xFF0000 });
				}
			}
		}
		else {
			// �I�����Ă��Ȃ������狭���\�����Ȃ�
			isHighlighted_ = false;
		}
	}

	// �J�[�\�������������ɔ�������g���K�[�Ō��ʉ���炷�����肷��
	if ((!preIsHighlighted_ && isHighlighted_) && isSelect_ && !selectSound_.expired()) selectSound_.lock()->Play(false);

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
	// �N���b�N���̌��ʉ���炷
	if(!onClickSound_.expired()) onClickSound_.lock()->Play(false);

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

void AbstractUI::SetOnClickSound(std::weak_ptr<Sound> sound) {
	onClickSound_ = sound;
}

bool AbstractUI::IsSelect(void) const {
	return isSelect_;
}

void AbstractUI::SetSelect(bool flag) {
	isSelect_ = flag;
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
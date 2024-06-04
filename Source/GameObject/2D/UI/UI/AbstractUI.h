#pragma once
#include <memory>
#include <functional>
#include "../../../../Common/Vector2.h"
#include "../../../../Common/Handle/PixelShader/PixelShader.h"
#include "../../GameObject2D.h"
#include "UI_Info.h"

class Graphic;
class Sound;
class PixelShader;
/// @brief UI�̒��ۃN���X�ł�
/// @note 2D��UI�Ŏg�����Ƃ�O��ɐ݌v���Ă���̂�3D�ł͓����܂���
class AbstractUI : public GameObject2D {
public:
	AbstractUI(void);
	~AbstractUI(void) = default;

	/// @brief �R���X�g���N�^
	/// @param canvasSize UI�̃L�����o�X�̃T�C�Y
	/// @param originType �ǂ������_�ɂ��邩
	AbstractUI(
		const Vector2<float>& canvasSize, 
		UI::UI_ORIGIN_TYPE originType,
		bool isClickable,
		const std::function<void(void)> onClickCallBack,
		std::weak_ptr<PixelShader> usingPixelShader,
		int usingPixelShaderEventID
	);

	/// @brief �����\������Ă邩��Ԃ�
	/// @param flag �����\������Ă邩
	[[nodiscard]] bool IsHighlighted(void) const;

	/// @brief �����\�����邩���Z�b�g
	/// @param flag �����\�����邩
	void SetHighlighted(bool flag);

	/// @brief ����UI���N���b�N�ł��邩��Ԃ�
	/// @return �N���b�N�ł��邩
	[[nodiscard]] bool IsClickable(void) const;

	/// @brief ����UI���N���b�N�ł��邩���Z�b�g
	/// @param isClickable �N���b�N�ł��邩
	void SetClickable(bool isClickable);

	/// @brief �N���b�N���ꂽ���ɌĂяo�����R�[���o�b�N�֐����Z�b�g
	/// @param callBack �R�[���o�b�N�֐�
	void SetOnClickCallBack(const std::function<void(void)>& callBack);

	/// @brief �`��p�̃L�����o�X��Ԃ� 
	/// @return �`��p�̃L�����o�X
	std::weak_ptr<Graphic> GetRenderCanvas(void);

	/// @brief ����UI�̎�ނ�Ԃ� 
	/// @return UI�̎��
	[[nodiscard]] UI::UI_TYPE GetType(void) const;

	/// @brief ����UI���ǂ������_�ɂ��Ă邩��Ԃ� 
	/// @return ���_�̎��
	[[nodiscard]] UI::UI_ORIGIN_TYPE GetOriginType(void) const;

	/// @brief UI��`�悵�I������L�����o�X���X�N���[���̂ǂ��ɕ`�悷�邩�𒲐�����I�t�Z�b�g��Ԃ�
	/// @return �I�t�Z�b�g
	[[nodiscard]] Vector2<float> GetCanvasRenderOffset(void) const;

	/// @brief �`�悷��ۂɎg�p����s�N�Z���V�F�[�_�[��Ԃ� 
	/// @return �s�N�Z���V�F�[�_�[
	[[nodiscard]] std::weak_ptr<PixelShader> GetUsingPixelShader(void) const;

	/// @brief �s�N�Z���V�F�[�_�[�̒萔�o�b�t�@���g���C�x���gID�Ԃ� 
	/// @return �C�x���gID
	[[nodiscard]] int GetUsingPixelShaderEventID(void) const;

	/// @brief �s�N�Z���V�F�[�_�[�̒萔�o�b�t�@���g���C�x���gID���Z�b�g���� 
	/// @param �C�x���gID
	[[nodiscard]] void SetUsingPixelShaderEventID(int eventID);

	/// @brief �J�[�\�����������ۂɖ炷���ʉ�
	/// @brief ���܂�g��Ȃ����߃R���X�g���N�^�ł͎󂯎��Ȃ��ł�
	/// @param sound ���ʉ�
	void SetSelectSound(std::weak_ptr<Sound> sound);
protected:
	// �����\������Ă邩
	bool isHighlighted_;

	// �����\������Ă邩(1�t���[���O�̂��)
	bool preIsHighlighted_;

	// ����UI�̓N���b�N�ł��邩
	bool isClickable_;

	// �N���b�N���ꂽ���ɌĂяo�����R�[���o�b�N�֐�(isClickable_��true�̎��̂ݎg�p�ł��܂�)
	std::function<void(void)> onClickCallBack_;

	// ����UI��`�悷�邽�߂̃L�����o�X
	std::shared_ptr<Graphic> renderCanvas_;

	// ����UI�̎��
	UI::UI_TYPE type_;

	// ����UI�̂ǂ������_�ɂ��邩
	UI::UI_ORIGIN_TYPE originType_;

	// �`�悷��ۂɎg�p����s�N�Z���V�F�[�_�[
	std::weak_ptr<PixelShader> usingPixelShader_;

	// �g�p����s�N�Z���V�F�[�_�̒萔�o�b�t�@���g���C�x���gID
	int usingPixelShaderEventID_;

	// �J�[�\�����������ۂɖ炷��
	std::weak_ptr<Sound> selectSound_;

	// �O������B�����邽�߂�public�ɂ��Ȃ�
	void Init_GameObject2D(void) override;
	void Update_GameObject2D(void) override;
	void Release_GameObject2D(void) override;
	
	// �h���N���X�Œ�`
	virtual void Init_UI(void) = 0;
	virtual void Update_UI(void) = 0;
	virtual void Release_UI(void) = 0;
	
	/// @brief UI�𒷉������Ă��鎞�̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickDown(void);

	/// @brief UI�𗣂������̏��� (isClickable_��true�̎��̂ݎg�p�ł��܂�)
	virtual void OnClickUp(void);

	/// @brief �����\������Ă鎞�̍X�V���� 
	virtual void HighlightUpdate(void);

	/// @brief �N���b�N���ꂽ���ɌĂ΂��R�[���o�b�N�֐����Ăяo��
	void OnClick(void);
};


#pragma once

/// @brief �`��@�\������񋟂���C���^�[�t�F�C�X
class IRenderer {
public:
	virtual ~IRenderer(void) = default;

	/// @brief �`�揈�� 
	virtual void Render(void) = 0;

	/// @brief �`�揈��(�f�o�b�O�p) 
	virtual void DebugRender(void) = 0;
};
#pragma once

/// @brief �`��@�\������񋟂���C���^�[�t�F�C�X
class IRenderer {
public:
	virtual ~IRenderer(void) = default;

	/// @brief �`�揈�� 
	virtual void Render(void) = 0;
};
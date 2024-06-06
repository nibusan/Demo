//#pragma once
//#include <vector>
//#include <memory>
//#include "../../Renderer/AbstractRenderer.h"
//#include "GameObject3D.h"
//
//class Model;
///// @brief �`��@�\��񋟂��钊�ۃN���X
//class GameObject3DRenderer : AbstractRenderer {
//public:
//	GameObject3DRenderer(void) = default;
//	virtual ~GameObject3DRenderer(void) = default;
//
//	/// @brief �`��J�n����
//	void Begin(void) override;
//
//	/// @brief �`�揈�� 
//	void Render(void) override;
//
//	/// @brief �`��I������ 
//	void End(void) override;
//
//	/// @brief �`�揈��(�f�o�b�O�p) 
//	void DebugRender(void) override;
//
//	/// @brief �`��Ώۂ̃I�u�W�F�N�g���폜���ꂽ����Ԃ� 
//	/// @return �폜���ꂽ��
//	bool IsDeleted(void) const override;
//private:
//	std::shared_ptr<Object3D>
//};
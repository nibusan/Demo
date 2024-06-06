#pragma once
#include <vector>
#include <memory>
#include "../Common/StaticSingleton.h"

class Camera;
class AbstractRenderer;
class RenderManager : public StaticSingleton<RenderManager> {
public:
	~RenderManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(RenderManager);

	void Init(void);
	void Render(void);
	void Release(void);

	/// @brief 2D�̃����_���[��ǉ�
	/// @param renderer2D 2D�����_���[
	void AddRenderer2D(std::shared_ptr<AbstractRenderer> renderer2D);

	/// @brief 3D�̃����_���[��ǉ�
	/// @param renderer3D 3D�����_���[
	void AddRenderer3D(std::shared_ptr<AbstractRenderer> renderer3D);

	/// @brief ���C���J�������Z�b�g
	/// @param mainCamera ���C���J����
	void SetMainCamera(std::shared_ptr<Camera> mainCamera);
private:
	// 2D�̃����_���[���i�[
	std::vector<std::shared_ptr<AbstractRenderer>> renderer2D_;
	
	// 3D�̃����_���[���i�[
	std::vector<std::shared_ptr<AbstractRenderer>> renderer3D_;

	// ���C���̃J����
	std::shared_ptr<Camera> mainCamera_;

	// �f�o�b�O�p�̃��O���i�[
	std::vector<std::string> debugLogs_;

	RenderManager() = default;

	/// @brief �o�^����Ă�2D�̃����_���[��`�悷�� 
	void Render2D(void);

	/// @brief �o�^����Ă�3D�̃����_���[��`�悷�� 
	void Render3D(void);
};
#pragma once
#include <vector>
#include <memory>
#include "UILayerType.h"

class AbstractUI;
/// @brief ������UI�̂܂Ƃ܂�(�|�[�Y��ʂȂ�)���ꖇ�̃��C���[�Ƃ��Ĉ�����N���X
class AbstractUILayer {
public:
	AbstractUILayer(void) = default;
	~AbstractUILayer(void) = default;

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Release(void) = 0;
private:
	// ���̃��C���[�ɓo�^���ꂽUI
	std::vector<std::shared_ptr<AbstractUI>> uis_;

	/// @brief �w�肳�ꂽUILayer��ǂݍ���
	/// @param type UILayer�̎��
	void LoadUILayer(UILayer::TYPE type);
};
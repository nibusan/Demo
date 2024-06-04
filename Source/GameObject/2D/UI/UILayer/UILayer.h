#pragma once
#include <vector>
#include <memory>
#include "UILayerInfo.h"

class AbstractUI;
/// @brief ������UI�̂܂Ƃ܂�(�|�[�Y��ʂȂ�)���ꖇ�̃��C���[�Ƃ��Ĉ�����N���X
class UILayer {
public:
	UILayer(void) = default;
	~UILayer(void) = default;

	void Init(void);
	void Update(void);
	void Release(void);

	/// @brief �w�肳�ꂽUILayer��ǂݍ���
	/// @param type UILayer�̎��
	void LoadUILayer(UILayerInfo::TYPE type);
private:
	// ���̃��C���[�ɓo�^���ꂽUI
	std::vector<std::shared_ptr<AbstractUI>> uis_;

};
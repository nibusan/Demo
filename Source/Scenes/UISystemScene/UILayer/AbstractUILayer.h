#pragma once
#include <vector>
#include <memory>

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
	std::vector<AbstractUI> uis_;

};
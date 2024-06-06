#pragma once
#include <memory>
#include "../Common/StaticSingleton.h"

class AbstractUI;
class UIInputManager : public StaticSingleton<UIInputManager> {
public:
	~UIInputManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(UIInputManager);

	void Init(void);
	void Update(void);

	/// @brief ���ɂǂꂩ��UI��I�����Ă邩��Ԃ� 
	/// @return UI��I�����Ă邩
	bool IsSelected(void) const;

	/// @brief ���ɂǂꂩ��UI��I�����Ă邩���Z�b�g����
	/// @param flag UI��I�����Ă邩
	void SetSelected(bool flag);

	/// @brief ���ɂǂꂩ��UI���N���b�N���Ă邩��Ԃ� 
	/// @return UI���N���b�N���Ă邩
	bool IsClicked(void) const;

	/// @brief ���ɂǂꂩ��UI���N���b�N���Ă邩���Z�b�g����
	/// @param flag UI���N���b�N���Ă邩
	void SetClicked(bool flag);

	/// @brief ���ݑI�����Ă���UI���Z�b�g
	/// @param ui UI
	void SetSelectUI(std::weak_ptr<AbstractUI> ui);

	/// @brief �n���ꂽUI�����ɃZ�b�g����Ă�UI�Ɠ�������Ԃ�
	/// @param ui ��r����UI
	/// @return �������ǂ���
	bool IsSameUI(std::weak_ptr<AbstractUI> ui);
private:
	// ���ɂǂꂩ��UI��I�����Ă邩
	bool selected_;

	// ���ɂǂꂩ��UI���N���b�N���Ă邩
	bool clicked_;

	// ���ݑI�����Ă���UI
	std::weak_ptr<AbstractUI> selectUI_;

	UIInputManager(void);
};


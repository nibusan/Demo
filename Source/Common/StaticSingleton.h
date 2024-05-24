#pragma once

// �V���O���g���݌v�ŋ��ʂŎg���������ȗ����邽�߂̃}�N��
#define THIS_CLASS_IS_STATIC_SINGLETON(TYPE)\
TYPE(const TYPE&) = delete;\
TYPE& operator=(const TYPE&) = delete;\
TYPE(const TYPE&&) = delete;\
TYPE& operator=(TYPE&) = delete;\
friend class StaticSingleton<TYPE>;

// �p�����邾���ŃV���O���g���ɂł���֗��N���X
template<typename T>
class StaticSingleton {
public:
	// �C���X�^���X��Ԃ�
	static T& GetInstance(void) {
		static T instance_;
		return instance_;
	}

	// �R�s�[�ł��Ȃ��悤�ɂ��邽�߃R�s�[�R���X�g���N�^�Ȃǂ��ĂׂȂ�����
	StaticSingleton(const StaticSingleton&) = delete;
	StaticSingleton& operator=(const StaticSingleton&) = delete;
	StaticSingleton(const StaticSingleton&&) = delete;
	StaticSingleton& operator=(StaticSingleton&) = delete;
protected:
	StaticSingleton(void) = default;
	~StaticSingleton(void) = default;
};
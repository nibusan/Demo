#pragma once
#include <concepts>
#include "../Common/Vector2.h"

/// @brief �Q�[���I�u�W�F�N�g�̊�b�f�[�^���Ǘ�����N���X
/// @note �p�x��2D�A3D�ŗv�f�����ς��̂Ŕh���N���X�Œ�`���Ă܂�

/// @brief concept��template�̈����𐧌����Ă܂�
/// @tparam T �������ŊǗ����邩(2D:Vector2<float> or 3D:Vector3<float>)
template <typename T>
concept VectorType_ = 
	// ���e����Ă���^���ǂ����𔻒肷��
	std::is_same_v<T, Vector2<float>>;
template <VectorType_ T>
class Transform {
public:
	// parent = �e�̒l
	// local = ���g�̒l
	// current = �v�Z�ς݂̌��݂̒l
	// (parent + local = current)

	// ���W
	T parentPos_;
	T localPos_;
	T currentPos_;

	// �X�P�[���l
	T parentScl_;
	T localScl_;
	T currentScl_;

	Transform(void) = default;
	~Transform(void) = default;
};

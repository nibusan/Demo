#pragma once

/// @brief �Q�[���I�u�W�F�N�g�̊�b�f�[�^���Ǘ�����N���X
/// @tparam T �������ŊǗ����邩(2D:Vector2,3D:Vector3)
template <typename T>
class Transform {
public:
	// ���W
	T pos_;
	T localpos_;

	// �p�x
	T rot_;
	T localrot_;

	// �X�P�[���l
	T scl_;
	T localscl_;

	Transform(void) = default;
	~Transform(void) = default;
};

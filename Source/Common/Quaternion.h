#pragma once
#include <DxLib.h>
#include "Vector3.h"

class Quaternion {
public:

	static constexpr float kEpsilonNormalSqrt = 1e-15F;

	double w;
	double x;
	double y;
	double z;

	Quaternion(void);
	Quaternion(const Vector3<double>& rad);
	Quaternion(double w, double x, double y, double z);

	~Quaternion(void);

	// �I�C���[�p����N�H�[�^�j�I���֕ϊ�
	static Quaternion Euler(const Vector3<double>& rad);
	static Quaternion Euler(double radX, double radY, double radZ);

	// �N�H�[�^�j�I���̍���
	static Quaternion Mult(const Quaternion& q1, const Quaternion& q2);
	Quaternion Mult(const Quaternion& q) const;

	// �w�莲���w��p���A��]������
	static Quaternion AngleAxis(double rad, Vector3<double> axis);

	// ���W����]������
	static Vector3<double> PosAxis(const Quaternion& q, Vector3<double> pos);
	Vector3<double> PosAxis(Vector3<double> pos) const;

	// �N�H�[�^�j�I������I�C���[�p�֕ϊ�
	static Vector3<double> ToEuler(const Quaternion& q);
	Vector3<double> ToEuler(void) const;

	// �N�H�[�^�j�I������s��֕ϊ�
	static MATRIX ToMatrix(const Quaternion& q);
	MATRIX ToMatrix(void) const;

	// �x�N�g������N�H�[�^�j�I���ɕϊ�
	static Quaternion LookRotation(Vector3<double> dir);
	static Quaternion LookRotation(Vector3<double> dir, Vector3<double> up);

	// �s�񂩂�N�H�[�^�j�I���ɕϊ�
	static Quaternion GetRotation(MATRIX mat);

	// ��{�x�N�g�����擾
	Vector3<double> GetForward(void) const;
	Vector3<double> GetBack(void) const;
	Vector3<double> GetRight(void) const;
	Vector3<double> GetLeft(void) const;
	Vector3<double> GetUp(void) const;
	Vector3<double> GetDown(void) const;

	// ����
	static double Dot(const Quaternion& q1, const Quaternion& q2);
	double Dot(const Quaternion& b) const;

	// ���K��
	static Quaternion Normalize(const Quaternion& q);
	Quaternion Normalized(void) const;
	void Normalize(void);

	// �t�N�H�[�^�j�I��
	Quaternion Inverse(void) const;

	// ���ʕ��
	static Quaternion Slerp(Quaternion from, Quaternion to, double t);

	// �Q�̃x�N�g���Ԃ̉�]�ʂ��擾����
	static Quaternion FromToRotation(Vector3<double> fromDir, Vector3<double> toDir);
	static Quaternion RotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta);
	static double Angle(const Quaternion& q1, const Quaternion& q2);
	static Quaternion SlerpUnclamped(Quaternion a, Quaternion b, float t);
	static Quaternion Identity(void);

	double Length(void) const;
	double LengthSquared(void) const;
	Vector3<double> xyz(void) const;

	// �Ώە����̉�]
	void ToAngleAxis(float* angle, Vector3<double>* axis);

private:

	// ��{�x�N�g�����擾
	Vector3<double> GetDir(Vector3<double> dir) const;

	Quaternion operator*(float& rhs);
	const Quaternion operator*(const float& rhs);
	Quaternion operator+(Quaternion& rhs);
	const Quaternion operator+(const Quaternion& rhs);

};

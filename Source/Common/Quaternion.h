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

	// オイラー角からクォータニオンへ変換
	static Quaternion Euler(const Vector3<double>& rad);
	static Quaternion Euler(double radX, double radY, double radZ);

	// クォータニオンの合成
	static Quaternion Mult(const Quaternion& q1, const Quaternion& q2);
	Quaternion Mult(const Quaternion& q) const;

	// 指定軸を指定角分、回転させる
	static Quaternion AngleAxis(double rad, Vector3<double> axis);

	// 座標を回転させる
	static Vector3<double> PosAxis(const Quaternion& q, Vector3<double> pos);
	Vector3<double> PosAxis(Vector3<double> pos) const;

	// クォータニオンからオイラー角へ変換
	static Vector3<double> ToEuler(const Quaternion& q);
	Vector3<double> ToEuler(void) const;

	// クォータニオンから行列へ変換
	static MATRIX ToMatrix(const Quaternion& q);
	MATRIX ToMatrix(void) const;

	// ベクトルからクォータニオンに変換
	static Quaternion LookRotation(Vector3<double> dir);
	static Quaternion LookRotation(Vector3<double> dir, Vector3<double> up);

	// 行列からクォータニオンに変換
	static Quaternion GetRotation(MATRIX mat);

	// 基本ベクトルを取得
	Vector3<double> GetForward(void) const;
	Vector3<double> GetBack(void) const;
	Vector3<double> GetRight(void) const;
	Vector3<double> GetLeft(void) const;
	Vector3<double> GetUp(void) const;
	Vector3<double> GetDown(void) const;

	// 内積
	static double Dot(const Quaternion& q1, const Quaternion& q2);
	double Dot(const Quaternion& b) const;

	// 正規化
	static Quaternion Normalize(const Quaternion& q);
	Quaternion Normalized(void) const;
	void Normalize(void);

	// 逆クォータニオン
	Quaternion Inverse(void) const;

	// 球面補間
	static Quaternion Slerp(Quaternion from, Quaternion to, double t);

	// ２つのベクトル間の回転量を取得する
	static Quaternion FromToRotation(Vector3<double> fromDir, Vector3<double> toDir);
	static Quaternion RotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta);
	static double Angle(const Quaternion& q1, const Quaternion& q2);
	static Quaternion SlerpUnclamped(Quaternion a, Quaternion b, float t);
	static Quaternion Identity(void);

	double Length(void) const;
	double LengthSquared(void) const;
	Vector3<double> xyz(void) const;

	// 対象方向の回転
	void ToAngleAxis(float* angle, Vector3<double>* axis);

private:

	// 基本ベクトルを取得
	Vector3<double> GetDir(Vector3<double> dir) const;

	Quaternion operator*(float& rhs);
	const Quaternion operator*(const float& rhs);
	Quaternion operator+(Quaternion& rhs);
	const Quaternion operator+(const Quaternion& rhs);

};

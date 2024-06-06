#pragma once
#include <string>
#include <DxLib.h>
#include "../Common/Vector2.h"
#include "../Common/Vector3.h"
#include "../Common/Quaternion.h"
class Utility
{

public:

	// ラジアン(rad)・度(deg)変換用
	static constexpr float RAD2DEG = (180.0f / DX_PI_F);
	static constexpr float DEG2RAD = (DX_PI_F / 180.0f);

	// 回転軸
	static constexpr Vector3<double> AXIS_X = { 1.0f, 0.0f, 0.0f };
	static constexpr Vector3<double> AXIS_Y = { 0.0f, 1.0f, 0.0f };
	static constexpr Vector3<double> AXIS_Z = { 0.0f, 0.0f, 1.0f };

	// 方向
	static constexpr Vector3<double> DIR_F = { 0.0f, 0.0f, 1.0f };
	static constexpr Vector3<double> DIR_B = { 0.0f, 0.0f, -1.0f };
	static constexpr Vector3<double> DIR_R = { 1.0f, 0.0f, 0.0f };
	static constexpr Vector3<double> DIR_L = { -1.0f, 0.0f, 0.0f };
	static constexpr Vector3<double> DIR_U = { 0.0f, 1.0f, 0.0f };
	static constexpr Vector3<double> DIR_D = { 0.0f, -1.0f, 0.0f };

	static constexpr float kEpsilonNormalSqrt = 1e-15F;

	// 四捨五入
	static int Round(float v);

	// ラジアン(rad)から度(deg)
	static double Rad2DegD(double rad);
	static float Rad2DegF(float rad);
	static int Rad2DegI(int rad);

	// 度(deg)からラジアン(rad)
	static double Deg2RadD(double deg);
	static float Deg2RadF(float deg);
	static int Deg2RadI(int deg);

	// 0～360度の範囲に収める
	static double DegIn360(double deg);

	// 0(0)～2π(360度)の範囲に収める
	static double RadIn2PI(double rad);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	static int DirNearAroundRad(float from, float to);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	static int DirNearAroundDeg(float from, float to);

	// 線形補間
	static int Lerp(int start, int end, float t);
	static float Lerp(float start, float end, float t);
	static double Lerp(double start, double end, double t);
	static Vector2<float> Lerp(const Vector2<float>& start, const Vector2<float>& end, float t);
	static Vector3<double> Lerp(const Vector3<double>& start, const Vector3<double>& end, float t);

	// 角度の線形補間
	static double LerpDeg(double start, double end, double t);

	// 色の線形補間
	static COLOR_F Lerp(const COLOR_F& start, const COLOR_F& end, float t);

	// ベジェ曲線
	static Vector2<float> Bezier(const Vector2<float>& p1, const Vector2<float>& p2, const Vector2<float>& p3, float t);
	static Vector3<double> Bezier(const Vector3<double>& p1, const Vector3<double>& p2, const Vector3<double>& p3, float t);

	// 比較
	static bool Equals(const Vector3<double>& v1, const Vector3<double>& v2);
	static bool EqualsVZero(const Vector3<double>& v1);

	// 2つのベクトルの間の角度
	static double AngleDeg(const Vector3<double>& from, const Vector3<double>& to);

	// 文字列変換
	static std::string WStringToString(const std::wstring& oWString);	//wstringをstringへ変換
	static std::wstring StringToWString(const std::string& oString);	//stringをwstringへ変換
};


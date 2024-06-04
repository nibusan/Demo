#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <DxLib.h>
#include "Utility.h"

int Utility::Round(float v) {
	return static_cast<int>(roundf(v));
}

double Utility::Rad2DegD(double rad) {
	return rad * (180.0 / DX_PI);
}

float Utility::Rad2DegF(float rad) {
	return rad * (180.0f / DX_PI_F);
}

int Utility::Rad2DegI(int rad) {
	return rad * Round(180.0f / DX_PI_F);
}

double Utility::Deg2RadD(double deg) {
	return deg * (DX_PI / 180.0);
}

float Utility::Deg2RadF(float deg) {
	return deg * (DX_PI_F / 180.0f);
}

int Utility::Deg2RadI(int deg) {
	return deg * Round(DX_PI_F / 180.0f);
}

double Utility::DegIn360(double deg) {
	deg = fmod(deg, 360.0);
	if (deg < 0.0f) {
		deg += 360.0;
	}
	return deg;
}

double Utility::RadIn2PI(double rad) {
	rad = fmod(rad, DX_TWO_PI);
	if (rad < 0.0) {
		rad += DX_TWO_PI;
	}
	return rad;
}

int Utility::DirNearAroundRad(float from, float to) {

	float ret = 1.0f;

	float diff = to - from;

	if (diff >= 0.0f) {

		// 比較元よりも時計回りに位置する

		if (diff > DX_PI_F) {
			// でも、180度以上離れているので、反時計回りの方が近い
			ret = -1.0f;
		}
		else {
			// 時計回り
			ret = 1.0f;
		}

	}
	else {

		// 比較元よりも反時計回りに位置する

		if (diff < -DX_PI_F) {
			// でも、180度以上離れているので、時計回りの方が近い
			ret = 1.0f;
		}
		else {
			// 反時計回り
			ret = -1.0f;
		}

	}

	return static_cast<int>(ret);

}

int Utility::DirNearAroundDeg(float from, float to) {

	float ret = 1.0f;

	float diff = to - from;

	if (diff >= 0.0f) {

		// 比較元よりも時計回りに位置する

		if (diff > 180.0f) {
			// でも、180度以上離れているので、反時計回りの方が近い
			ret = -1.0f;
		}
		else {
			// 時計回り
			ret = 1.0f;
		}

	}
	else {

		// 比較元よりも反時計回りに位置する

		if (diff < -180.0f) {
			// でも、180度以上離れているので、時計回りの方が近い
			ret = 1.0f;
		}
		else {
			// 反時計回り
			ret = -1.0f;
		}

	}

	return static_cast<int>(ret);

}

int Utility::Lerp(int start, int end, float t) {
	// 線形補間
	if (t >= 1.0f) {
		return end;
	}

	int ret = start;
	ret += Round(t * static_cast<float>(end - start));
	return ret;
}

float Utility::Lerp(float start, float end, float t) {
	// 線形補間
	if (t >= 1.0f) {
		return end;
	}

	float ret = start;
	ret += t * (end - start);
	return ret;
}

double Utility::Lerp(double start, double end, double t) {
	// 線形補間
	if (t >= 1.0) {
		return end;
	}

	double ret = start;
	ret += t * (end - start);
	return ret;
}

Vector2<float> Utility::Lerp(const Vector2<float>& start, const Vector2<float>& end, float t) {
	// 線形補間
	if (t >= 1.0f) {
		return end;
	}

	Vector2<float> ret = start;
	ret.x += Round(t * static_cast<float>((end.x - start.x)));
	ret.y += Round(t * static_cast<float>((end.y - start.y)));
	return ret;
}

Vector3<double> Utility::Lerp(const Vector3<double>& start, const Vector3<double>& end, float t) {
	// 線形補間
	if (t >= 1.0f) {
		return end;
	}

	Vector3<double> ret = start;
	ret.x += t * (end.x - start.x);
	ret.y += t * (end.y - start.y);
	ret.z += t * (end.z - start.z);

	return ret;
}

double Utility::LerpDeg(double start, double end, double t) {

	double ret;

	double diff = end - start;
	if (diff < -180.0) {
		end += 360.0;
		ret = Lerp(start, end, t);
		if (ret >= 360.0) {
			ret -= 360.0;
		}
	}
	else if (diff > 180.0) {
		end -= 360.0;
		ret = Lerp(start, end, t);
		if (ret < 0.0) {
			ret += 360.0;
		}
	}
	else {
		ret = Lerp(start, end, t);
	}

	return ret;

}

COLOR_F Utility::Lerp(const COLOR_F& start, const COLOR_F& end, float t) {
	// 線形補間
	if (t >= 1.0f) {
		return end;
	}

	COLOR_F ret = start;
	ret.r += t * (end.r - start.r);
	ret.g += t * (end.g - start.g);
	ret.b += t * (end.b - start.b);
	ret.a += t * (end.a - start.a);
	return ret;
}

Vector2<float> Utility::Bezier(const Vector2<float>& p1, const Vector2<float>& p2, const Vector2<float>& p3, float t) {
	Vector2<float> a = Lerp(p1, p2, t);
	Vector2<float> b = Lerp(p2, p3, t);
	return Lerp(a, b, t);
}

Vector3<double> Utility::Bezier(const Vector3<double>& p1, const Vector3<double>& p2, const Vector3<double>& p3, float t) {
	Vector3<double> a = Lerp(p1, p2, t);
	Vector3<double> b = Lerp(p2, p3, t);
	return Lerp(a, b, t);
}

bool Utility::Equals(const Vector3<double>& v1, const Vector3<double>& v2) {
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
		return true;
	}
	return false;
}

bool Utility::EqualsVZero(const Vector3<double>& v1) {
	Vector3<double> v2 = {};
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
		return true;
	}
	return false;
}

double Utility::AngleDeg(const Vector3<double>& from, const Vector3<double>& to) {
	// sqrt(a) * sqrt(b) = sqrt(a * b) -- valid for real numbers
	auto fLen = from.Length();
	auto tLen = to.Length();
	auto denominator = sqrt(fLen * tLen);
	if (denominator < kEpsilonNormalSqrt) {
		return 0.0f;
	}

	//float dot = std::clamp(Dot(from, to) / denominator, -1.0f, 1.0f);
	//auto dot = Dot(from, to) / denominator;
	auto dot = from.Dot(to) / denominator;
	if (dot < -1.0f) {
		dot = -1.0f;
	}
	if (dot > 1.0f) {
		dot = 1.0f;
	}

	return acos(dot) * (180.0 / DX_PI);
}

std::string Utility::WStringToString(std::wstring oWString) {
	// wstring → SJIS
	int iBufferSize = WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str()
		, -1, (char*)NULL, 0, NULL, NULL);

	// バッファの取得
	CHAR* cpMultiByte = new CHAR[iBufferSize];

	// wstring → SJIS
	WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str(), -1, cpMultiByte
		, iBufferSize, NULL, NULL);

	// stringの生成
	std::string oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);

	// バッファの破棄
	delete[] cpMultiByte;

	// 変換結果を返す
	return(oRet);
}



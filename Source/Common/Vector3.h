#pragma once
#include <concepts>
#include <cmath>
//#include <assert.h>

//三次元ベクトル(int,float,doubleのみ)
template <typename T>
concept ValidType_3 = std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>;
template <ValidType_3 T>
struct Vector3 {
	T x, y, z;

	Vector3(void) = default;
	constexpr Vector3(T ax,T ay,T az){
		x = ax;
		y = ay;
		z = az;
	};
	~Vector3(void) = default;

	Vector3 operator+(const Vector3& rval) const {
		return { x + rval.x, y + rval.y, z + rval.z };
	};

	Vector3 operator-(const Vector3& rval) const{
		return { x - rval.x, y - rval.y, z - rval.z };
	};

	Vector3 operator*(const float scale) const {
		return { x * scale, y * scale, z * scale };
	};

	Vector3 operator*(const Vector3& scale) const {
		return { x * scale.x, y * scale.y, z * scale.z };
	};

	Vector3 operator/(const float div) const {
		if(div == 0.0f) {
			return { x, y, z };
		}
		return { x / div, y / div, z / div };
	};

	Vector3 operator/(const Vector3& div) const {
		if (div.x == 0.0f || div.y == 0.0f || div.z == 0.0f) {
			return div;
		}
		return { x / div.x, y / div.y, z / div.z };
	};

	void operator+=(const Vector3& rval) {
		x += rval.x;
		y += rval.y;
		z += rval.z;
	};

	void operator-=(const Vector3& rval) {
		x -= rval.x;
		y -= rval.y;
		z -= rval.z;
	};

	void operator*=(const float scale) {
		x *= scale;
		y *= scale;
		z *= scale;
	};

	void operator/=(const float div) {
		//assert(div != 0.0f);
		x /= div;
		y /= div;
		z /= div;
	};

	bool operator==(const Vector3& rval) {
		return (x == rval.x) && (y == rval.y) && (z == rval.z);
	}

	bool operator!=(const Vector3& rval) {
		return (x != rval.x) || (y != rval.y) || (z != rval.z);
	}

	T Dot(const Vector3& rval) const {
		return x * rval.x + y * rval.y + z * rval.z;
	};

	Vector3 Cross(const Vector3& rval) const {
		return {
			y * rval.z - rval.y * z,
			z * rval.x - rval.z * x,
			x * rval.y - rval.x * y
		};
	};

	T Length(void) const {
		return std::sqrtf(x * x + y * y + z * z);
	};

	Vector3 Normalize(void) const {
		T length = Length();
		return { x / length, y / length, z / length };
	};

	Vector3<int> ToVector3i(void) const {
		return Vector3<int>(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
	}

	Vector3<float> ToVector3f(void) const {
		return Vector3<float>(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
	}

	Vector3<double> ToVector3d(void) const {
		return Vector3<double>(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
	}
};
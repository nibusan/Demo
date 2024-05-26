#pragma once
#include <concepts>
#include <cmath>
//#include <assert.h>

//�񎟌��x�N�g��(int,float,double�̂�)
template <typename T>
concept ValidType = std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>;
template <ValidType T>
struct Vector2 {
	T x, y;

	Vector2(void) = default;
	Vector2(T ax,T ay){
		x = ax;
		y = ay;
	};
	~Vector2(void) = default;

	Vector2 operator+(const Vector2& rval) const {
		return { x + rval.x, y + rval.y };
	};

	Vector2 operator-(const Vector2& rval) const{
		return { x - rval.x, y - rval.y };
	};

	Vector2 operator*(const float scale) const {
		return { x * scale, y * scale };
	};

	Vector2 operator*(const Vector2& scale) const {
		return { x * scale.x, y * scale.y };
	};

	Vector2 operator/(const float div) const {
		if(div == 0.0f) {
			return { x, y };
		}
		return { x / div, y / div };
	};

	Vector2 operator/(const Vector2& div) const {
		if (div.x == 0.0f || div.y == 0.0f) {
			return div;
		}
		return { x / div.x, y / div.y };
	};

	void operator+=(const Vector2& rval) {
		x += rval.x;
		y += rval.y;
	};

	void operator-=(const Vector2& rval) {
		x -= rval.x;
		y -= rval.y;
	};

	void operator*=(const float scale) {
		x *= scale;
		y *= scale;
	};

	void operator/=(const float div) {
		//assert(div != 0.0f);
		x /= div;
		y /= div;
	};

	bool operator==(const Vector2& rval) {
		return (x == rval.x) && (y == rval.y);
	}

	bool operator!=(const Vector2& rval) {
		return (x != rval.x) || (y != rval.y);
	}

	T Dot(const Vector2& rval) const {
		return x * rval.x + y * rval.y;
	};

	T Cross(const Vector2& rval) const {
		return x * rval.y - y * rval.x;
	};

	T Length(void) const {
		return hypotf(x, y);
	};

	Vector2 Normalize(void) const {
		T length = Length();
		return { x / length, y / length };
	};

	Vector2<int> ToVector2i(void) const {
		return Vector2<int>(static_cast<int>(x), static_cast<int>(y));
	}

	Vector2<float> ToVector2f(void) const {
		return Vector2<float>(static_cast<float>(x), static_cast<float>(y));
	}

	Vector2<double> ToVector2d(void) const {
		return Vector2<double>(static_cast<double>(x), static_cast<double>(y));
	}
};
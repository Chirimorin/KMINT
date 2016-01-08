/**
* Vector2.cpp
* 2-component vector class.
*
* This file is part of Jonathan Fischer's Xcode Game Template:
* https://github.com/mohiji/xcode-templates
*/

#include "Vector2.h"
#include <assert.h>
#include <set>
#include <SDL.h>
#include <SDL_stdinc.h>
#include "FWApplication.h"

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2 &copy)
{
	x = copy.x;
	y = copy.y;
}

Vector2& Vector2::operator= (const Vector2 &other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2 &other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2 &other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2& Vector2::operator/=(float scalar)
{
	assert(scalar != 0.0f);
	x /= scalar;
	y /= scalar;
	return *this;
}

Vector2 operator+ (const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator- (const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator* (const Vector2 &a, float scalar)
{
	return Vector2(a.x * scalar, a.y * scalar);
}

Vector2 operator* (float scalar, const Vector2 &a)
{
	return Vector2(a.x * scalar, a.y * scalar);
}

Vector2 operator/ (const Vector2 &a, float divisor)
{
	assert(divisor != 0.0f);
	return Vector2(a.x / divisor, a.y / divisor);
}

float Magnitude(const Vector2 &v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

float MagnitudeSquared(const Vector2 &v)
{
	return v.x * v.x + v.y * v.y;
}

float MagnitudeWrapped(const Vector2& v)
{
	float magnitudeSquared = INFINITY;

	for (float x = -800; x <= 800; x+=800)
	{
		for (float y = -600; y <= 600; y += 600)
		{
			float newMagnitude = MagnitudeSquared(v + Vector2{ x, y });
			if (newMagnitude < magnitudeSquared)
			{
				magnitudeSquared = newMagnitude;
			}
		}
	}

	return sqrtf(magnitudeSquared);
}

Vector2 Normal(const Vector2 &v)
{
	float mag = Magnitude(v);
	if (mag == 0.0f) return Vector2(0, 0);
	else return v / mag;
}

float DotProduct(const Vector2 &a, const Vector2 &b)
{
	return a.x * b.x + a.y * b.y;
}

// dot-perp operation defined in:
// http://www.geometrictools.com/Documentation/IntersectionLine2Circle2.pdf
float DotPerp(const Vector2 &a, const Vector2 &b)
{
	return a.x * b.y - a.y * b.x;
}

Vector2 Reflect(const Vector2 &V, const Vector2 &N)
{
	return (2 * DotProduct(N, V)) * N - V;
}


// TODO: truncate fucntie toevoegen
Vector2 Truncate(const Vector2 &v, float max)
{
	if (Magnitude(v) > max) {
		Vector2 temp = Normal(v) * max; 
		return Vector2(temp.x, temp.y);
	}
	return v;
}

// TODO: perp fucntie toevoegen
Vector2 Perp(const Vector2 &v)
{
	return Vector2(-v.y, v.x);
}

double Angle(const Vector2& v)
{
	return (std::atan2(v.y, v.x) / M_PI) * 180.0;
}

void WrapAround(Vector2& v)
{
	int w = 800;
	int h = 600;

	while (v.x > w)
	{
		v.x -= w;
	}
	while (v.x < 0)
	{
		v.x += w;
	}
	while (v.y > h)
	{
		v.y -= h;
	}
	while (v.y < 0)
	{
		v.y += h;
	}
}

Vector2 WrappedDistance(Vector2& v)
{
	float magnitudeSquared = INFINITY;
	Vector2 result;

	for (float x = -800; x <= 800; x += 800)
	{
		for (float y = -600; y <= 600; y += 600)
		{
			Vector2 newVector = v + Vector2{ x, y };
			float newMagnitude = MagnitudeSquared(newVector);
			if (newMagnitude < magnitudeSquared)
			{
				magnitudeSquared = newMagnitude;
				result = newVector;
			}
		}
	}

	return result;
}

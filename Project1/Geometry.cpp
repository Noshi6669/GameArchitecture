#include <cmath>
#include <utility>
#include "Geometry.h"

float Rect::Left() const
{
    return center.x - w;
}

float Rect::Right() const
{
    return center.x + w;
}

float Rect::Top() const
{
    return center.y - h;
}

float Rect::Bottom() const
{
    return center.y + h;
}

float Rect::Width() const
{
    return w * 2.0f;
}

float Rect::Height() const
{
    return h * 2.0f;
}

float Vector2::Magnitude() const
{
    return std::hypotf(x, y);
}

void Vector2::Normalize()
{
    auto mag = Magnitude();
    x /= mag;
    y /= mag;
}

Vector2 Vector2::Normalized() const
{
    auto mag = Magnitude();

    return Vector2(x / mag, y / mag);
}

void Vector2::operator+=(const Vector2& v)
{
    x += v.x;
    y += v.y;
}

void Vector2::operator-=(const Vector2& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2::Rotate90(void)
{
    std::swap(x, y);
}


//ベクトルの足し算
Vector2 operator+(const Vector2& lval, const Vector2& rval)
{
    return Vector2{ lval.x + rval.x,lval.y + rval.y };
}

//ベクトルの引き算
Vector2 operator-(const Vector2& lval, const Vector2& rval)
{
    return Vector2{ lval.x - rval.x,lval.y - rval.y };
}

//ベクトルのスカラー倍
Vector2 operator*(const Vector2& lval, float num)
{
    return Vector2{ lval.x * num,lval.y * num };
}

//ベクトルのスカラー除
Vector2 operator/(const Vector2& lval, float num)
{
    if (num != 0) 
    {
        return Vector2{ lval.x / num,lval.y / num };
    }
    else {
        return Vector2{ 0,0 };
    }

}

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

bool Vector2::operator==(const Vector2& v)
{
    return ((x == v.x) && (y == v.y));
}

void Vector2::Rotate90(void)
{
    std::swap(x, y);
    x = -x;
}

Vector2 Vector2::Rotated90(void)
{
    return { -y,x };
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

<<<<<<< HEAD
///内積を返す
float
Dot(const Vector2& va, const Vector2& vb) {
    return va.x * vb.x + va.y * vb.y;
}

///外積を返す
float
Cross(const Vector2& va, const Vector2& vb) {
    return va.x * vb.y - vb.x * va.y;
}

///内積演算子
float
operator*(const Vector2& va, const Vector2& vb) {
    return Dot(va, vb);
}

///外積演算子
float
operator%(const Vector2& va, const Vector2& vb) {
    return Cross(va, vb);
}
=======
float Dot(const Vector2& lval, const Vector2& rval)
{
    return lval.x * rval.x + lval.y * rval.y;
}

float Cross(const Vector2& lval, const Vector2& rval)
{
    return lval.x * rval.y - lval.y * rval.x;
}
>>>>>>> f3d85b3c842ce1d55054c33ef183b131fe2efa37

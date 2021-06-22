#pragma once

//2Dベクトル
struct Vector2
{
	float x, y;
	Vector2() :x(0), y(0) {};
	Vector2(float inx, float iny) :x(inx), y(iny) {};
	//ベクトルの大きさを返す関数
	float Magnitude()const;
	//ベクトルを正規化する関数
	void Normalize();
	//ベクトルを正規化したベクトルを返す
	Vector2 Normalized() const;


	void operator+=(const Vector2& v);
	void operator-=(const Vector2& v);
	bool operator==(const Vector2& v);
	//90度回転させる
	void Rotate90(void);
	Vector2 Rotated90(void);
	static const Vector2 Zero() {
		return { 0.0f,0.0f };
	}
};

//ベクトルの足し算
Vector2 operator+(const Vector2& lval, const Vector2& rval);

//ベクトルの引き算
Vector2 operator-(const Vector2& lval, const Vector2& rval);

//ベクトルのスカラー倍
Vector2 operator*(const Vector2& lval, float num);

//ベクトルのスカラー除
Vector2 operator/(const Vector2& lval, float num);



//座標＝ベクトルなので、座標として定義する
using Position2 = Vector2;

//矩形の当たり判定
struct Rect
{
	Position2 center;	//中心点
	float w, h;			//w・・・幅,	h・・・高さ
	float Left()const;		//左のＸ座標を返す
	float Right()const;		//右のＸ座標を返す
	float Top()const;		//
	float Bottom()const;	//
	float Width()const;
	float Height()const;
};

//円の構造体
struct Circle
{
	Position2 center;	//中心点
	float radius;		//半径
};
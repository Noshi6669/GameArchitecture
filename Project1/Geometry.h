#pragma once

//2D�x�N�g��
struct Vector2
{
	float x, y;
	Vector2() :x(0), y(0) {};
	Vector2(float inx, float iny) :x(inx), y(iny) {};
	//�x�N�g���̑傫����Ԃ��֐�
	float Magnitude()const;
	//�x�N�g���𐳋K������֐�
	void Normalize();
	//�x�N�g���𐳋K�������x�N�g����Ԃ�
	Vector2 Normalized() const;


	void operator+=(const Vector2& v);
	void operator-=(const Vector2& v);
	bool operator==(const Vector2& v);
	//90�x��]������
	void Rotate90(void);
	Vector2 Rotated90(void);
	static const Vector2 Zero() {
		return { 0.0f,0.0f };
	}
};

//�x�N�g���̑����Z
Vector2 operator+(const Vector2& lval, const Vector2& rval);

//�x�N�g���̈����Z
Vector2 operator-(const Vector2& lval, const Vector2& rval);

//�x�N�g���̃X�J���[�{
Vector2 operator*(const Vector2& lval, float num);

//�x�N�g���̃X�J���[��
Vector2 operator/(const Vector2& lval, float num);



//���W���x�N�g���Ȃ̂ŁA���W�Ƃ��Ē�`����
using Position2 = Vector2;

//��`�̓����蔻��
struct Rect
{
	Position2 center;	//���S�_
	float w, h;			//w�E�E�E��,	h�E�E�E����
	float Left()const;		//���̂w���W��Ԃ�
	float Right()const;		//�E�̂w���W��Ԃ�
	float Top()const;		//
	float Bottom()const;	//
	float Width()const;
	float Height()const;
};

//�~�̍\����
struct Circle
{
	Position2 center;	//���S�_
	float radius;		//���a
};
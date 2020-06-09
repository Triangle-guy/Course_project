/****************************************************************************
 *  \file Vector2D.cpp
 *  \brief
 *      - Имплементация класса для простого двухмерного вектора
 *  \author Рощин Константин
*****************************************************************************/
#include "Vector2D.h"
#define _USE_MATH_DEFINES 
#include "cmath"

/*!*************************************************************************
  Vector2D()

  \brief
    Конструктор для класса Vector2D

***************************************************************************/
Vector2D::Vector2D()
	: x(0)
	, y(0)
{

}

/*!*************************************************************************
  Vector2D(float xCoor, float yCoor)

  \brief
    Конструктор для класса Vector2D
  \param xCoor
    X-координата вектора
  \param yCoor
    Y-координата вектора

***************************************************************************/
Vector2D::Vector2D(float xCoor, float yCoor)
	: x(xCoor)
	, y(yCoor)
{

}

/*!*************************************************************************
  Vector2D(const Vector2D& other)

  \brief
    Конструктор для класса Vector2D
  \param other
    Копируемый вектор

***************************************************************************/
Vector2D::Vector2D(const Vector2D& other)
	: x(other.x)
	, y(other.y)
{

}

/*!*************************************************************************
  Vector2D(float angle, AngleUnits units)

  \brief
    Конструктор для класса Vector2D
  \param angle
    Угол наклона
  \param units
    Единицы измерения угла
***************************************************************************/
Vector2D::Vector2D(float angle, AngleUnits units)
{
	CalculateFromAngle(angle, units);
}

/*!*************************************************************************
  ~Vector2D()

  \brief
    Деструктор для вектора

***************************************************************************/
Vector2D::~Vector2D()
{

}

//Math

/*!*************************************************************************
  Set(float xCoor, float yCoor)

  \brief
    Сеттер для координат вектора
  \param xCoor
    X-координата вектора
  \param yCoor
    Y-координата вектора

***************************************************************************/
Vector2D& Vector2D::Set(float xCoor, float yCoor)
{
	x = xCoor;
	y = yCoor;
	return *this;
}

/*!*************************************************************************
  Invert()

  \brief
    Получение инвертированнного вектора

***************************************************************************/
Vector2D& Vector2D::Invert()
{
	x = -x;
	y = -y;
	return *this;
}

/*!*************************************************************************
  GetNormal() const

  \brief
    Получение единичного вектора того же направления

***************************************************************************/
Vector2D Vector2D::GetNormal() const
{
	Vector2D result;
	float length = GetLength();
	result.x = x / length;
	result.y = y / length;
	return result;
}

/*!*************************************************************************
  Normalize()

  \brief
    Превращение вектора в единичный того же направления

***************************************************************************/
Vector2D& Vector2D::Normalize()
{
	*this = GetNormal();
	return *this;
}

/*!*************************************************************************
  operator-()

  \brief
    Инвертирование вектора

***************************************************************************/
Vector2D& Vector2D::operator-()
{
	return Invert();
}

/*!*************************************************************************
  operator-()

  \brief
    Инвертирование вектора

***************************************************************************/
Vector2D Vector2D::operator-(const Vector2D& other) const
{
	Vector2D result(x - other.x, y - other.y);
	return result;
}


Vector2D& Vector2D::operator-=(const Vector2D& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}


Vector2D Vector2D::operator+(const Vector2D& other) const
{
	Vector2D result(x + other.x, y + other.y);
	return result;
}


Vector2D& Vector2D::operator+=(const Vector2D& other)
{
	x += other.x;
	y += other.y;
	return *this;
}


Vector2D& Vector2D::operator*()
{
	return Normalize();
}
float Vector2D::operator*(const Vector2D& other) const
{
	float newx = x * other.x;
	float newy = y * other.y;
	return x + y;
}


Vector2D Vector2D::operator*(const float& scale) const
{
	Vector2D result(*this);
	result.x *= scale;
	result.y *= scale;
	return result;
}


Vector2D& Vector2D::operator*=(const float& scale)
{
	x *= scale;
	y *= scale;
	return *this;
}


float Vector2D::GetLength() const
{
	return sqrtf(GetLengthSquared());
}

float Vector2D::GetLengthSquared() const
{
	return x * x + y * y;
}


float Vector2D::DistanceTo(const Vector2D& other) const
{
	Vector2D result(*this);
	result = other - result;
	return result.GetLength();
}


Vector2D& Vector2D::CalculateFromAngle(float angle, AngleUnits units)
{
	if (units == AngleUnits::Degrees)
	{
		angle = (angle * (float)M_PI) / 180.0f;
	}
	x = cosf(angle);
	y = sinf(angle);
	return *this;
}


Vector2D& Vector2D::Rotate(const Vector2D& pivot, float angle, AngleUnits units)
{

	if (units == AngleUnits::Radians)
	{
		angle = (angle * 180) / (float)M_PI;
	}

	float s = sinf(angle);
	float c = cosf(angle);
	x -= pivot.x;
	y -= pivot.y;
	float xnew = x * c - y * s;
	float ynew = x * s + y * c;
	x = xnew + pivot.x;
	y = ynew + pivot.y;
	return *this;

}


float Vector2D::ToAngle(AngleUnits units)
{
	if (units == AngleUnits::Degrees)
	{
		return (atan2f(y, x) * 180) / (float)M_PI;
	}
	return atan2f(y, x);
}


Vector2D Vector2D::Midpoint(const Vector2D& other)
{
	Vector2D newVec;
	newVec.x = (x + other.x) / 2;
	newVec.y = (y + other.y) / 2;
	return newVec;
}


Vector2D* Line::CalculateIntesectionWith(Line& other)
{
	float uA = ((other.endPoint.x - other.startingPoint.x) * (startingPoint.y - other.startingPoint.y) - (other.endPoint.y - other.startingPoint.y) * (startingPoint.x - other.startingPoint.x)) / ((other.endPoint.y - other.startingPoint.y) * (endPoint.x - startingPoint.x) - (other.endPoint.x - other.startingPoint.x) * (endPoint.y - startingPoint.y));
	float uB = ((endPoint.x - startingPoint.x) * (startingPoint.y - other.startingPoint.y) - (endPoint.y - startingPoint.y) * (startingPoint.x - other.startingPoint.x)) / ((other.endPoint.y - other.startingPoint.y) * (endPoint.x - startingPoint.x) - (other.endPoint.x - other.startingPoint.x) * (endPoint.y - startingPoint.y));

	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
	{
		return new Vector2D(startingPoint.x + (uA * (endPoint.x - startingPoint.x)), startingPoint.y + (uA * (endPoint.y - startingPoint.y)));
	}

	return nullptr;
}

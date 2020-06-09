/****************************************************************************
 *  Имя файла: Vector2D.h
 *  Описание:
 *      - Интерфейс для двухмерного вектора
 *  Автор: Рощин константин
*****************************************************************************/
#pragma once


enum class AngleUnits
{
  Degrees,
  Radians
};

enum class VectorType
{
  Vector,
  Point
};

class Vector2D
{
public:

  //Конструкторы и деструкторы
  Vector2D();
  Vector2D(float xCoor, float yCoor = 0);
  Vector2D(const Vector2D& other);
  Vector2D(float angle, AngleUnits units);
  ~Vector2D();

  //Математика
  Vector2D& Set(float xCoor, float yCoor);
  Vector2D& Invert();
  Vector2D GetNormal()const;
  Vector2D& Normalize();
  Vector2D& operator-();
  Vector2D operator-(const Vector2D& other) const;
  Vector2D& operator-=(const Vector2D& other);
  Vector2D operator+(const Vector2D& other) const;
  Vector2D& operator+=(const Vector2D& other);
  Vector2D& operator*();
  float operator*(const Vector2D& other) const;
  Vector2D operator*(const float& scale) const;
  Vector2D& operator*=(const float& scale);
  float GetLength()const;
  float GetLengthSquared()const;
  float DistanceTo(const Vector2D& other) const;
  Vector2D& CalculateFromAngle(float angle, AngleUnits units);
  Vector2D& Rotate(const Vector2D& pivot, float angle, AngleUnits units);
  float ToAngle(AngleUnits units);
  Vector2D Midpoint(const Vector2D& other);
  //Значения

  float x;
  float y;

};


struct Line
{
  Vector2D* CalculateIntesectionWith(Line& other);
  Vector2D startingPoint;
  Vector2D endPoint;
};




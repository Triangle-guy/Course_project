/****************************************************************************
 *  Имя файла: Shapes.cpp
 *  Описание:
 *      - Имплементация класса для простых геометрических фигур
 *  Автор: Рощин Константин
*****************************************************************************/
#include "Shapes.h"
#include "Vector2D.h"

#define _USE_MATH_DEFINES 
#include "cmath"



EquilateralTriangle::EquilateralTriangle(float centerX, float centerY, float sideLength)
{
  float rBig = sideLength / (1.73205080757f * 2.0f);
  c.x = centerX;
  c.y = centerY - rBig;
  Vector2D temp;
  (temp.CalculateFromAngle(300, AngleUnits::Degrees)).Normalize() *= sideLength;
  a = c + temp;
  (temp.CalculateFromAngle(240, AngleUnits::Degrees)).Normalize() *= sideLength;
  b = c + temp;
}

EquilateralTriangle::EquilateralTriangle(Vector2D& tip, float sideLength)
{
  this->c = tip;
  Vector2D temp;
  (temp.CalculateFromAngle(300, AngleUnits::Degrees)).Normalize() *= sideLength;
  this->a = c + temp;
  (temp.CalculateFromAngle(240, AngleUnits::Degrees)).Normalize() *= sideLength;
  this->b = c + temp;
}

EquilateralTriangle& EquilateralTriangle::Rotate(float angle, AngleUnits units)
{
  if (units == AngleUnits::Degrees)
  {
    angle = (angle * (float)M_PI) / 180.0f;
  }


  float length = a.DistanceTo(c);
  float radiusSmall = length/ 1.73205080757f;
  
  Vector2D angleVector = a.Midpoint(b);
  angleVector = c - angleVector;
  (angleVector.Normalize()) *= radiusSmall;

  Vector2D centre = c - angleVector;

 // c.Rotate(centre, angle, units);
  a.Rotate(c, angle, units);
  b.Rotate(c, angle, units);

  return *this;
}

/****************************************************************************
 *  Имя файла: Shapes.h
 *  Описание:
 *      - Интерфейс для класса для простых геометрических фигур
 *  Автор: Рощин Константин
*****************************************************************************/

#pragma once

#include "Vector2D.h"

struct Triangle
{
  Vector2D a;
  Vector2D b;
  Vector2D c;
};

struct EquilateralTriangle : public Triangle
{
  EquilateralTriangle(float centerX, float centerY, float sideLength);
  EquilateralTriangle(Vector2D& tip, float sideLength);
  EquilateralTriangle& Rotate(float angle, AngleUnits units);
};

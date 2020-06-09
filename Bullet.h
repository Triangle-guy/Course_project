/****************************************************************************
 *  Имя файла: Bullet.h
 *  Описание:
 *      - Интерфейс класса Bullet, который отвечает за обработку и
 *        прорисовку пуль
 *  Автор: Рощин Константин
*****************************************************************************/
#pragma once
#include "Actor.h"
#include "Bullet.h"
#include <vector>

typedef class Vector2D Vector2D;

class Bullet : public Actor
{
public:
  Bullet(float x, float y, Vector2D& direction, float speed);
  Bullet(const Vector2D& position, Vector2D& direction, float );
  void Draw();
  void Update();
private:
  Vector2D direction_;
  float speed_;
};


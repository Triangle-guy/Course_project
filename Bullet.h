/****************************************************************************
 *  \file Bullet.h
 *  \brief
 *      - Интерфейс класса Bullet, который отвечает за обработку и
 *        прорисовку пуль
 *  \author Рощин Константин
*****************************************************************************/
#pragma once
#include "Actor.h"
#include "Bullet.h"
#include <vector>

typedef class Vector2D Vector2D;

class Bullet : public Actor //!< Класс Bullet
{
public:
  //! Конструктор
  Bullet(float x, float y, Vector2D& direction, float speed);

  //! Конструктор
  Bullet(const Vector2D& position, Vector2D& direction, float );

  //! Прорисовка
  void Draw();

  //! Обновление
  void Update();
private:
  Vector2D direction_; //!< Направление
  float speed_;        //!< Скороть
};


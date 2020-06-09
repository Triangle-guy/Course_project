/****************************************************************************
 *  \file Bullet.cpp
 *  \brief
 *      - Имплементация класса Bullet, который отвечает за обработку и 
 *        прорисовку пуль
 *  \author Рощин Константин
*****************************************************************************/
#include "Bullet.h"
#include "Vector2D.h"
#include "Graphics.h"
#include "main.h"

/*!*************************************************************************
  Bullet(float x, float y, Vector2D& direction, float speed)

  \brief
    Конструктор для класса Bullet
  \param x
    X-координата для спавна пули
  \param y
    Y-координата для спавна пули
  \param direction
    Направление пули (единичный вектор)
  \param speed
    Скорость пули

***************************************************************************/
Bullet::Bullet(float x, float y, Vector2D& direction, float speed)
  :Actor(ActorType::Bullet, x, y)
  ,direction_(direction)
  ,speed_(speed)
{
  SetTimer(51);
}

/*!*************************************************************************
  Bullet(float x, float y, Vector2D& direction, float speed)

  \brief
    Конструктор для класса Bullet, использующий Vector2D
  \param Position
    Позиция для спавна пули
  \param direction
    Направление пули (единичный вектор)
  \param speed
    Скорость пули

***************************************************************************/
Bullet::Bullet(const Vector2D& position, Vector2D& direction, float speed)
  :Actor(ActorType::Bullet, position)
  ,direction_(direction)
  ,speed_(speed)
{
  SetTimer(51);
}


/*!*************************************************************************
  void Draw()

  \brief
    Рисует круг с радиусом BULLET_RADIUS вокруг позиции пули

***************************************************************************/
void Bullet::Draw()
{
  Graphics::DrawCircle(GetPosition(), BULLET_RADIUS, 0x42DAF5, GetAlpha());
}

/*!*************************************************************************
  void Update()

  \brief
    Обновляет таймер, позицию и скорость пули

***************************************************************************/
void Bullet::Update()
{
  DecrementTimer();
  if (GetTimer() <= 0)
  {
    Kill();
  }
  speed_ -= 0.5;
  if (speed_ < 0)
  {
    speed_ = 0;
  }
  SetPosition(GetPosition() + direction_ * speed_);
  SetAlpha(GetAlpha() - 5);
}

﻿/****************************************************************************
 *  Имя файла: Bullet.cpp
 *  Описание:
 *      - Имплементация класса Bullet, который отвечает за обработку и 
 *        прорисовку пуль
 *  Автор: Рощин Константин
*****************************************************************************/
#include "Bullet.h"
#include "Vector2D.h"
#include "Graphics.h"
#include "main.h"

Bullet::Bullet(float x, float y, Vector2D& direction, float speed)
  :Actor(ActorType::Bullet, x, y)
  ,direction_(direction)
  ,speed_(speed)
{
  SetTimer(51);
}

Bullet::Bullet(const Vector2D& position, Vector2D& direction, float speed)
  :Actor(ActorType::Bullet, position)
  ,direction_(direction)
  ,speed_(speed)
{
  SetTimer(51);
}

void Bullet::Draw()
{
  Graphics::DrawCircle(GetPosition(), BULLET_RADIUS, 0x42DAF5, GetAlpha());
}

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

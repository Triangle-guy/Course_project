/****************************************************************************
 *  \file Player.cpp
 *  \brief
 *      - Имплементация класса Player, который отвечает за управление, 
 *        обновление и прорисовку корабля
 *  \author Рощин Константин
*****************************************************************************/
#include "Player.h"
#include "Graphics.h"
#include "main.h"
#include "EventHandler.h"
#include "Bullet.h"

/*!*************************************************************************
  Player(float x, float y)

  \brief
    Конструктор для класса Player
  \param x
    X-координата для спавна игрока
  \param y
    Y-координата для спавна игрока

***************************************************************************/
Player::Player(float x, float y)
  :Actor(ActorType::Player, x, y)
  ,body_(x, y, ACTOR_SIZE)
  ,speed_(0)
  ,rotationSpeed_(0)
{
  Vector2D temp;
  temp.x = body_.c.x;
  temp.y = body_.c.y - 5;

  for (int i = 0; i < 3; i++)
  {
    circles_.push_back(temp);
    temp.Rotate(body_.c, 120, AngleUnits::Degrees);
  }

}

/*!*************************************************************************
  void Draw()

  \brief
    Выводит игрока на экран

***************************************************************************/
void Player::Draw()
{
  Graphics::DrawTriangle(body_, 0x00FF00, GetAlpha());
  for (int i = 0; i < circles_.size(); i++)
  {
    Graphics::DrawCircle(circles_[i], 5, 0x42DAF5, GetAlpha());
  }
}

/*!*************************************************************************
  void Update()

  \brief
    Обновляет позицию игрока, считывает нажатия клавиатуры и проверяет колизию

***************************************************************************/
void Player::Update()
{
  
  if (IsDead())
  {
    OnDeath();
    return;
  }

  Vector2D startC = body_.c;
  Vector2D direction = body_.a.Midpoint(body_.b);
  direction = body_.c - direction;
  direction.Normalize();

  if (EventHandler::KeyIsDown(SDL_SCANCODE_LEFT))
  {
    rotationSpeed_ += 0.5;
    if (rotationSpeed_ > 5)
    {
      rotationSpeed_ = 5;
    }
    
  }
  else if (EventHandler::KeyIsDown(SDL_SCANCODE_RIGHT))
  { 
    rotationSpeed_ -= 0.5;
    if (rotationSpeed_  < -5)
    {
      rotationSpeed_ = -5;
    }
   
  }
  else
  {
    if (rotationSpeed_ > 0)
    {
      rotationSpeed_ -= 0.5;
      if (rotationSpeed_ < 0)
      {
        rotationSpeed_ = 0;
      }
    }
    else if (rotationSpeed_ < 0)
    {
      rotationSpeed_ += 0.5;
      if (rotationSpeed_ > 0)
      {
        rotationSpeed_ = 0;
      }
    }
  }
  body_.Rotate(-rotationSpeed_, AngleUnits::Degrees);

  if (EventHandler::KeyIsDown(SDL_SCANCODE_UP))
  {
    speed_ += 0.1;
    if (speed_ > 5)
    {
      speed_ = 5;
    }
  }
  else
  {
    speed_ -= 0.1;
    if (speed_ < 0)
    {
      speed_ = 0;
    }
  }
  body_.a += direction * speed_;
  body_.b += direction * speed_;
  body_.c += direction * speed_;

  if (EventHandler::KeyIsDown(SDL_SCANCODE_SPACE) && GetTimer() <= 0)
  {
    SetTimer(5);
    Bullet bul(body_.c, direction, 20 + speed_);
    bullets_.push_back(bul);
  }

  Vector2D endC = body_.c;
  endC -= startC;

  for (int i = 0; i < circles_.size(); i++)
  {
    circles_[i] += endC;
    circles_[i].Rotate(body_.c, 1, AngleUnits::Degrees);
  }

  for (int i = 0; i < bullets_.size(); i++)
  {
    bullets_[i].Update();
    bullets_[i].Draw();
  }

  if (!bullets_.empty() && bullets_.begin()->IsDead())
  {
    bullets_.pop_front();
  }

  if (GetTimer() > 0)
  {
    DecrementTimer();
  }


  Vector2D newPos = body_.c - (direction * (ACTOR_SIZE/ 1.73205080757));
  //Graphics::DrawCircle(newPos, GetColliderRadius(), 0xFFFFFF, 255);

  SetPosition(newPos);

  if (CheckCollisionWithEnemies())
  {
    SetTimer(51);
    Kill();
  }



}


/*!*************************************************************************
  void OnDeath()

  \brief
    Играет анимацию "смерти" игрока, перехватывает Update() при смерти

***************************************************************************/
void Player::OnDeath()
{
  if (GetTimer() > 0)
  {
    body_.Rotate(10, AngleUnits::Degrees);
    Vector2D direction = (body_.c - GetPosition()).GetNormal();
    body_.a += direction * speed_;
    body_.b += direction * speed_;
    body_.c += direction * speed_;


    for (int i = 0; i < circles_.size(); i++)
    {
      direction = (circles_[i] - GetPosition()).GetNormal();
      circles_[i] += direction * 4;
    }
    SetAlpha(GetAlpha() - 4);
    DecrementTimer();
    return;
  }
  SetAlpha(0);
}

/*!*************************************************************************
  bool CheckCollisionWithEnemies()

  \brief
    Проверяет колизию с каждым из врагов
  \return
    Была ли колизия хость с одним врагом

***************************************************************************/
bool Player::CheckCollisionWithEnemies()
{
  for (int i = 0; i < Enemy::enemies.size(); i++)
  {
    if (CheckCollision(&(Enemy::enemies[i])))
    {
      return true;
    }
  }
  return false;
}



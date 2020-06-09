/****************************************************************************
 *  \file Enemy.cpp
 *  \brief
 *      - Имплементация класса Enemy, который отвечает за поведение,
 *        обновление и прорисовку врагов
 *  \author Рощин Константин
*****************************************************************************/
#include "Enemy.h"
#include "Graphics.h"
#include "main.h"
#include "Player.h"

//! Вектор, хранящий в себе врагов
std::vector<Enemy> Enemy::enemies;

/*!*************************************************************************
  Enemy(float x, float y, Player* player)

  \brief
    Конструктор для класса Enemy
  \param x
    X-координата для спавна пули
  \param y
    Y-координата для спавна пули
  \param player
    Указатель на игрока

***************************************************************************/
Enemy::Enemy(float x, float y, Player* player)
  : Actor(ActorType::Enemy, x, y)
  , speed_(5)
  , currState_(EnemyStates::Alive)
  , body_(x, y, ACTOR_SIZE)
  , player_(player)
{
 
}


/*!*************************************************************************
  bool CheckCollisionWithBullets()

  \brief
    Проверяет, произошла ли колизия с какой-либо пулей
  \return
    Статус колизии

***************************************************************************/
bool Enemy::CheckCollisionWithBullets()
{
  for (int i = 0; i < player_->bullets_.size(); i++)
  {
    if (CheckCollision(&(player_->bullets_[i])))
    {
      (player_->bullets_[i]).Kill();
      return true;
    }
  }
  return false;
}

/*!*************************************************************************
  void Draw()

  \brief
    Рисует треугольник по точкам, заданым в body_, два круга в цетре, и один
    круг в качестве хвоста

***************************************************************************/
void Enemy::Draw()
{
  Graphics::DrawTriangle(body_, 0xFF0000, GetAlpha());
  Graphics::DrawCircle(GetPosition(), 10, 0xFFFF00, GetAlpha());
  Graphics::DrawCircle(GetPosition(), 6, 0xFFFF00, GetAlpha());
  Graphics::DrawCircle(GetPosition(), 3, 0xFFFF00, GetAlpha());
  Graphics::DrawCircle(GetPosition() + (GetPosition() - body_.c), 5, 0xFFFFFF, GetAlpha());
}

/*!*************************************************************************
  void Update()

  \brief
    Обновляет позицию, угол вращение и проверяет колизию

***************************************************************************/
void Enemy::Update()
{
  if (IsDead())
  {
    OnDeath();
    return;
  }
  if (player_->IsDead())
  {
    return;
  }
  float targetAngle = (body_.c - player_->GetPosition()).ToAngle(AngleUnits::Degrees);
  body_.Rotate(180 + targetAngle - (body_.c - GetPosition()).ToAngle(AngleUnits::Degrees), AngleUnits::Degrees);

  Vector2D dirToPlayer = (body_.c - player_->GetPosition()).GetNormal();
  body_.a -= dirToPlayer * 1.5;
  body_.b -= dirToPlayer * 1.5;
  body_.c -= dirToPlayer * 1.5;

  Vector2D direction = body_.a.Midpoint(body_.b);
  direction = body_.c - direction;
  direction.Normalize();
  Vector2D newPos = body_.c - (direction * (ACTOR_SIZE / 1.73205080757));
  SetPosition(newPos);

  if (CheckCollisionWithBullets())
  {
    SetTimer(30);
    Kill();
  }

}

/*!*************************************************************************
  void OnDeath()

  \brief
    Перехватывает Update() при смерти

***************************************************************************/
void Enemy::OnDeath()
{
  if (GetTimer() > 0)
  {
    DecrementTimer();
    SetAlpha(GetAlpha() - 8);
    body_.Rotate(25, AngleUnits::Degrees);
    return;
  }
  SetAlpha(0);
}




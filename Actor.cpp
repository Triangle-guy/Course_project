/****************************************************************************
 *  \file Actor.cpp
 *  \brief
 *      - Имплементация абстрактного класса Actor, от которого будут наследовать
 *        враги и игрок
 *  \author Рощин Константин
*****************************************************************************/
#include "Actor.h"
#include "Graphics.h"
#include "main.h"


/*!*************************************************************************
  Actor(ActorType type, float x, float y

  \brief
    Конструктор для класса Actor
  \param type
    Тип создаваемого актора
  \param x
    X-координата для спавна актора
  \param y
    Y-координата для спавна актора

***************************************************************************/
Actor::Actor(ActorType type, float x, float y)
  : type_(type)
  , alpha_(255)
  , timer_(-1)
  , isDead_(false)
{
  position_.x = x;
  position_.y = y;

  switch (type)
  {
  case ActorType::Invalid:
    colliderRadius_ = 0;
    break;
  case ActorType::Player:
    colliderRadius_ = ACTOR_SIZE / (1.73205080757);
    break;
  case ActorType::Enemy:
    colliderRadius_ = ACTOR_SIZE / (1.73205080757);
    break;
  case ActorType::Bullet:
    colliderRadius_ = BULLET_RADIUS;
    break;
  default:
    colliderRadius_ = 0;
    break;
  }
}



/*!*************************************************************************
  Actor(ActorType type, float x, float y

  \brief
    Конструктор по умолчанию для класса Actor
  \param type
    Тип создаваемого актора
  \param x
    X-координата для спавна актора
  \param y
    Y-координата для спавна актора

***************************************************************************/
Actor::Actor(ActorType type, const Vector2D& position)
  : type_(type)
  , position_(position)
  , alpha_(255)
  , timer_(-1)
  , isDead_(false)
{
  switch (type)
  {
  case ActorType::Invalid:
    colliderRadius_ = 0;
    break;
  case ActorType::Player:
    colliderRadius_ = ACTOR_SIZE / (1.73205080757);
    break;
  case ActorType::Enemy:
    colliderRadius_ = ACTOR_SIZE / (1.73205080757);
    break;
  case ActorType::Bullet:
    colliderRadius_ = BULLET_RADIUS;
    break;
  default:
    colliderRadius_ = 0;
    break;
  }
}

/*!*************************************************************************
  Actor~()

  \brief
    Деструктор для актора

***************************************************************************/
Actor::~Actor()
{
}

/*!*************************************************************************
  Vector2D& GetPosition()

  \brief
    Геттер для позиции актора
  \return
    Позиция актора в настоящий момент

***************************************************************************/
Vector2D& Actor::GetPosition()
{
  return position_;
}

/*!*************************************************************************
  void SetPosition(const Vector2D& position)

  \brief
    Сеттер для позиции актора

***************************************************************************/
void Actor::SetPosition(const Vector2D& position)
{
  position_.x = position.x;
  position_.y = position.y;
}

/*!*************************************************************************
  int GetAlpha() const

  \brief
    Геттер для числа, обозначающего канал alpha (прозрачность) актора
  \return
    Значение канала альфа

***************************************************************************/
int Actor::GetAlpha() const
{
  return alpha_;
}

/*!*************************************************************************
  void SetAlpha(int alpha)

  \brief
    Сеттер для значения канала alpha актора

***************************************************************************/
void Actor::SetAlpha(int alpha)
{
  alpha_ = alpha;
}

/*!*************************************************************************
  void SetTimer(int timer)

  \brief
    Сеттер для локального таймера актора

***************************************************************************/
void Actor::SetTimer(int timer)
{
  timer_ = timer;
}

/*!*************************************************************************
  void DecrementTimer()

  \brief
    Уменьшает локальный таймер актора на 1

***************************************************************************/
void Actor::DecrementTimer()
{
  timer_--;
}

/*!*************************************************************************
  int GetTimer() const

  \brief
    Геттер для локального таймера актора
  \return
    Локальный таймер актора

***************************************************************************/
int Actor::GetTimer() const
{
  return timer_;
}

/*!*************************************************************************
  bool CheckCollision(ActorPtr other)

  \brief
    Проверяет два актора на предмет колизии 
  \param other
    Актор, с которым надо проверить колизию
  \return
    Произошла ли колизия, или нет

***************************************************************************/
bool Actor::CheckCollision(ActorPtr other)
{
  if (other->IsDead())
  {
    return false;
  }
  float distance = this->GetPosition().DistanceTo(other->GetPosition());
  if (distance <= this->colliderRadius_ + other->colliderRadius_)
  {
    return true;
  }
  return false;
}

/*!*************************************************************************
  ActorType GetType()

  \brief
    Геттер для типа актора
  \return
    Тип актора

***************************************************************************/

ActorType Actor::GetType()
{
  return type_;
}

/*!*************************************************************************
  bool IsDead()

  \brief
    Геттер для булевой переменной isDead_ актора
  \return
    isDead_

***************************************************************************/
bool Actor::IsDead()
{
  return isDead_;
}

/*!*************************************************************************
  void Kill()

  \brief
    "Убивает" актора, ставит значение переменной isDead_ на true

***************************************************************************/
void Actor::Kill()
{
  isDead_ = true;
}

/*!*************************************************************************
  float GetColliderRadius()

  \brief
    Геттер для радиуса круга колизии актора
  \return
    Радиус колизии

***************************************************************************/
float Actor::GetColliderRadius()
{
  return colliderRadius_;
}


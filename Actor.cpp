/****************************************************************************
 *  Имя файла: Actor.cpp
 *  Описание:
 *      - Имплементация абстрактного класса Actor, от которого будут наследовать
 *        враги и игрок
 *  Автор: Рощин Константин
*****************************************************************************/
#include "Actor.h"
#include "Graphics.h"
#include "main.h"

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

Actor::~Actor()
{
}

Vector2D& Actor::GetPosition()
{
  return position_;
}

void Actor::SetPosition(const Vector2D& position)
{
  position_.x = position.x;
  position_.y = position.y;
}

int Actor::GetAlpha() const
{
  return alpha_;
}

void Actor::SetAlpha(int alpha)
{
  alpha_ = alpha;
}

void Actor::SetTimer(int timer)
{
  timer_ = timer;
}

void Actor::DecrementTimer()
{
  timer_--;
}

int Actor::GetTimer() const
{
  return timer_;
}

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

ActorType Actor::GetType()
{
  return type_;
}

bool Actor::IsDead()
{
  return isDead_;
}

void Actor::Kill()
{
  isDead_ = true;
}

float Actor::GetColliderRadius()
{
  return colliderRadius_;
}


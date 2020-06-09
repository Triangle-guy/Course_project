/****************************************************************************
 *  Имя файла: Actor.h
 *  Описание:
 *      - Интерфейс абстрактного класса Actor, от которого будут наследовать
 *        враги и игрок
 *  Автор: Рощин Константин
*****************************************************************************/

#pragma once
#include "Vector2D.h"

typedef class  Actor* ActorPtr;

enum class ActorType
{
  Invalid = -1,
  Player,
  Enemy,
  Bullet
};

class  Actor
{
public:

  Actor(ActorType type, float x, float y);
  Actor(ActorType type, const Vector2D& position);
  ~Actor();
  Vector2D& GetPosition();
  void SetPosition(const Vector2D& position);

  int GetAlpha() const;

  void SetAlpha(int alpha);

  void SetTimer(int timer);

  void DecrementTimer();

  int GetTimer() const;

  virtual void Draw() = 0;

  virtual void Update() = 0;

  __inline virtual void OnDeath() { return; };


  bool CheckCollision(ActorPtr other);

  ActorType GetType();

  bool IsDead();

  void Kill();

  float GetColliderRadius();

private:

  ActorType type_;
  Vector2D position_;
  int alpha_;
  int timer_;
  bool isDead_;
  float colliderRadius_;
};


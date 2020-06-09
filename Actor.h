/****************************************************************************
 *  \file Actor.h
 *  \brief
 *      - Интерфейс абстрактного класса Actor, от которого будут наследовать
 *        враги и игрок
 *  \author Рощин Константин
*****************************************************************************/

#pragma once
#include "Vector2D.h"

typedef class  Actor* ActorPtr;

enum class ActorType //!< Энумерация для типов акторов
{
  Invalid = -1,
  Player,
  Enemy,
  Bullet
};

class  Actor //!< Абстрактный класс Actor
{
public:

  //! Конструктор
  Actor(ActorType type, float x, float y);

  //! Конструктор, использующий Vector2D
  Actor(ActorType type, const Vector2D& position);

  //! Деструктор
  ~Actor();

  //! Геттер позиции
  Vector2D& GetPosition();

  //! Сеттер позиции
  void SetPosition(const Vector2D& position);

  //! Геттер значения канала alpha
  int GetAlpha() const;

  //! Сеттер значения канала alpha
  void SetAlpha(int alpha);

  //! Сеттер локального таймера
  void SetTimer(int timer);

  //! Уменьшает локальный таймер на 1
  void DecrementTimer();

  //! Геттер локального таймера
  int GetTimer() const;

  //! Виртуальная функция, отвечающая за отрисовку актора
  virtual void Draw() = 0;

  //! Виртуальная функция, отвечающая за обновление актора
  virtual void Update() = 0;

  //! Виртуальная функция, которая вызывается при обновлении "мертвого" актора
  __inline virtual void OnDeath() { return; };

  //! Проеряет колизию между двумя акторами
  bool CheckCollision(ActorPtr other);

  //! Геттер для типа актора
  ActorType GetType();

  //! Геттер для статуса актора
  bool IsDead();

  //! "Убивает" актора
  void Kill();

  //! Геттер для радиуса колизии актора
  float GetColliderRadius();

private:


  ActorType type_;       //!< Тип актора
  Vector2D position_;    //!< Позиция актора
  int alpha_;            //!< Прозрачность
  int timer_;            //!< Локальный таймер
  bool isDead_;          //!< Статус
  float colliderRadius_; //!< Радиус круга колизии
};


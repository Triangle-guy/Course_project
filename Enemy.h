/****************************************************************************
 *  \file Enemy.h
 *  \brief
 *      - Интерфейс класса Enemy, который отвечает за поведение,
 *        обновление и прорисовку врагов
 *  \author Рощин Константин
*****************************************************************************/
#pragma once

#include "Actor.h"
#include "Shapes.h"
#include "Bullet.h"

typedef class Player Player;

enum class EnemyStates //!< Энумерация возможных стадий врага (НЕ ИСПОЛЬЗУЕТСЯ)
{
  Invalid = -1,
  Alive,
  Dead
};


class Enemy : public Actor //!< Класс Enemy
{
public:
  //!Вектор, хранящий в себе всех врагов
  static std::vector<Enemy> enemies;

  //!Конструктор
  Enemy(float x, float y, Player* player);

  //!Проверяет колизию со всеми пулями
  bool CheckCollisionWithBullets();

  //!Прорисовка врага
  void Draw();

  //! Обновление врага
  void Update();

  //! Функция, которая перехватывает Update при смерти
  void OnDeath();

private:
  float speed_;              //!< Скорость
  EnemyStates currState_;    //!< Статус врага (НЕ ИСПОЛЬЗУЕТСЯ)
  EquilateralTriangle body_; //!< "Тело", которое будет рисоваться
  Player* player_;           //!< Указатель на игрока, чтобы упростить навигацию и проверку колизии

};

/****************************************************************************
 *  \file Player.h
 *  \brief
 *      - Интерфейс класса Player, который отвечает за управление, обновление
 *        и прорисовку корабля
 *  \author Рощин Константин
*****************************************************************************/
#pragma once
#include "Actor.h"
#include "Shapes.h"
#include "Bullet.h"
#include "Vector2D.h"
#include "Enemy.h"

#include <vector>
#include <stack>


class Player : public Actor //!< Класс Actor
{
public:

  //! Конструктор
  Player(float x, float y);

  //! Прорисовка
  void Draw();
  
  //! Обработка
  void Update();

  //! Перехватывает Update() при смерти
  void OnDeath();

  //! Функция класса Enemy, которая проверяет колизию с пулями
  friend bool Enemy::CheckCollisionWithBullets();

  //! Проверяет колизию с врагами
  bool CheckCollisionWithEnemies();
private:

  float speed_;                   //!< скорость
  float rotationSpeed_;           //!< скорость вращения
  std::deque<Bullet> bullets_;    //!< вектор пуль
  std::vector<Vector2D> circles_; //!< вектор кружков, которые рисуятся с игроком
  EquilateralTriangle body_;      //!< "тело игрока"
};


/****************************************************************************
 *  Имя файла: Player.h
 *  Описание:
 *      - Интерфейс класса Player, который отвечает за управление, обновление
 *        и прорисовку корабля
 *  Автор: Рощин Константин
*****************************************************************************/
#pragma once
#include "Actor.h"
#include "Shapes.h"
#include "Bullet.h"
#include "Vector2D.h"
#include "Enemy.h"

#include <vector>
#include <stack>


class Player : public Actor
{
public:
  Player(float x, float y);

  void Draw();
  void Update();
  void OnDeath();
  friend bool Enemy::CheckCollisionWithBullets();
  bool CheckCollisionWithEnemies();
private:
  float speed_;
  float rotationSpeed_;
  std::deque<Bullet> bullets_;
  std::vector<Vector2D> circles_;
  EquilateralTriangle body_;
};


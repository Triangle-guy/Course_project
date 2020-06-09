/****************************************************************************
 *  Имя файла: Enemy.h
 *  Описание:
 *      - Интерфейс класса Enemy, который отвечает за поведение,
 *        обновление и прорисовку врагов
 *  Автор: Рощин Константин
*****************************************************************************/
#pragma once

#include "Actor.h"
#include "Shapes.h"
#include "Bullet.h"

typedef class Player Player;

enum class EnemyStates
{
  Invalid = -1,
  Alive,
  Dead
};

class Enemy : public Actor
{
public:
  static std::vector<Enemy> enemies;
  Enemy(float x, float y, Player* player);
  bool CheckCollisionWithBullets();
  void Draw();
  void Update();
  void OnDeath();

private:
  float speed_;
  EnemyStates currState_;
  EquilateralTriangle body_;
  Player* player_;

};

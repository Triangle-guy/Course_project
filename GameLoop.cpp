/****************************************************************************
 *  \file GameLoop.cpp
 *  \brief
 *      - Имплементация функций Init, Update и Shutdown для игрового цикла
 *  \author Рощин Константин
*****************************************************************************/

#include "main.h"
#include "Graphics.h"
#include "EventHandler.h"
#include "Vector2D.h"
#include "Actor.h"
#include "Shapes.h"
#include "Timer.h"
#include "Player.h"
#include "Enemy.h"

#include "ctime"
#include <cstdlib>


//!Генерирует случайное число от rangeMin до rangeMax
static int RandomRange(int rangeMin, int rangeMax);

bool reset = true;

int timer = 0;

int score = 0;

int highscore = 0;

char buf[64];

void GameLoopInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("TopDownShooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	screenSurface = SDL_GetWindowSurface(window);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	srand(time(NULL));

}

void GameLoopUpdate()
{
	
	Player player(400, 400);
	timer = 0;
	
	

	while (true)
	{
		Timer::FPS::GetTimeAtFrameStart();
		sprintf_s(buf, "Score: %d  Higschore: %d", score, highscore);
		SDL_SetWindowTitle(window, buf);

		timer--;
		if (timer <= 0)
		{
			timer = 46;
			int choice = RandomRange(0, 3);
			int xtemp;
			int ytemp;

			switch (choice)
			{
			case 0:
				xtemp = -50;
				ytemp = -50;
				break;
			case 1:
				xtemp = 1320;
				ytemp = -50;
				break;
			case 2:
				xtemp = 1320;
				ytemp = 770;
				break;
			case 3:
				xtemp = 50;
				ytemp = 770;
				break;
			default:
				xtemp = 350;
				ytemp = 350;
				break;
			}

			Enemy enemy(xtemp, ytemp, &player);
			Enemy::enemies.push_back(enemy);
		}
		

		EventHandler::InitEvents();

		Graphics::WipeScreen(0x0);
		if (EventHandler::KeyPressed(SDL_SCANCODE_ESCAPE))
		{
			reset = false;
			break;
		}
		else if (EventHandler::KeyPressed(SDL_SCANCODE_RETURN))
		{
			break;
		}

		
		for (int i = 0; i < Enemy::enemies.size(); i++)
		{
			Enemy::enemies[i].Update();
			Enemy::enemies[i].Draw();

			if (Enemy::enemies[i].IsDead() && Enemy::enemies[i].GetTimer() <= 0)
			{
				Enemy::enemies.erase(Enemy::enemies.begin() + i);
				score++;
			}
		}
		

		player.Update();

		if (false)
		{
			player.SetTimer(51);
			player.Kill();
		}

		player.Draw();

		

		Graphics::RenderFrame();
		EventHandler::ShutdownEvents();
		Timer::FPS::ForseFrameRate();
	}
}

void GameLoopShutdown()
{
	Enemy::enemies.erase(Enemy::enemies.begin(), Enemy::enemies.end());
	if (score > highscore)
	{
		highscore = score;
	}
	score = 0;

	if (reset)
	{
		GameLoopUpdate();
		GameLoopShutdown();
	}
}

static int RandomRange(int rangeMin, int rangeMax)
{
	
	int result = (int)((double)rand() / (double)(RAND_MAX + 1) * ((double)rangeMax - rangeMin + 1) + rangeMin);
	return result;
}
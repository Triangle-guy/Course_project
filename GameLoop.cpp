/****************************************************************************
 *  File name: GameLoop.cpp
 *  Description:
 *      - Implementation for the Init, Update and ShutDown functions of the 
 *        gameloop
 *  Author: Roschin Konstantin
*****************************************************************************/

#include "Main.h"

void GameLoopInit()
{
  SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("TopDownShooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 
	screenSurface = SDL_GetWindowSurface(window);
}

void GameLoopUpdate()
{
  while(true)
  {

  }
}

void GameLoopShutdown()
{

}

/****************************************************************************
 *  Имя файла: EventHandler.h
 *  Описание:
 *      - Интерфейс для обработчика событий; системы, которая упрощает работу
 *        с событиями SDL
 *  Автор: Рощин Константин
 ****************************************************************************/

#pragma once
#include "SDL.h"
#include <vector>


namespace EventHandler
{

	void InitEvents();

	void ShutdownEvents();
 
	bool KeyPressed(SDL_Scancode key);

  bool KeyIsDown(SDL_Scancode key);
}

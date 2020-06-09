/****************************************************************************
 *  \file EventHandler.h
 *  \brief
 *      - Интерфейс для обработчика событий; системы, которая упрощает работу
 *        с событиями SDL
 *  \author Рощин Константин
 ****************************************************************************/

#pragma once
#include "SDL.h"
#include <vector>


namespace EventHandler //!< Поле для обработки ивентов
{

  //!Инициализирует ивенты
	void InitEvents();

  //!Стирает ивенты из вектора
	void ShutdownEvents();
 
  //!Возвращает true, если нажата кнопка
	bool KeyPressed(SDL_Scancode key);

  //!Возвращает true, если зажата кнопка
  bool KeyIsDown(SDL_Scancode key);
}

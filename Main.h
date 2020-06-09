/****************************************************************************
 *  Имя файла: Main.h
 *  Описание:
 *      - Interface for the main header file, containing the main function
 *        and global variable delcarations
 *  Автор: Рощин Константин
*****************************************************************************/

#pragma once
#include <SDL.h>

#define ACTOR_SIZE 50.0f
#define BULLET_RADIUS 3.0f

/* Forward declararions */
typedef struct SDL_Window Window;
typedef struct SDL_Window* WindowPtr;

typedef struct SDL_Surface ScreenSurface;
typedef struct SDL_Surface* ScreenSurfacePtr;

typedef struct SDL_Renderer Renderer;
typedef struct SDL_Renderer* RendererPtr;

typedef class Bullet Bullet;

/* Global variables */
extern RendererPtr renderer;

extern WindowPtr window;

extern ScreenSurfacePtr screenSurface;


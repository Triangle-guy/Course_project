/****************************************************************************
 *  File name: Main.h
 *  Description:
 *      - Interface for the main header file, containing the main function
 *        and global variable delcarations
 *  Author: Roschin Konstantin
*****************************************************************************/

#pragma once
#include <SDL2/SDL.h>

/* Forward declararions */
typedef struct SDL_Window Window;
typedef struct SDL_Window* WindowPtr;

typedef struct SDL_Surface ScreenSurface;
typedef struct SDL_Surface* ScreenSurfacePtr;

typedef struct SDL_Renderer Renderer;
typedef struct SDL_Renderer* RendererPtr;

/* Global variables */
extern RendererPtr renderer;

extern WindowPtr window;

extern ScreenSurfacePtr screenSurface;




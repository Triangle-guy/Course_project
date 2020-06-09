/****************************************************************************
 *  Имя файла: Graphics.cpp
 *  Описание:
 *      - Имплементация различных графических функций, обертки для SDL функций
 *  Автор: Рощин Константин
*****************************************************************************/

#include "main.h"
#include "Graphics.h"

#define SPLIT_COLOUR(rgb) rgb / 0x10000, (rgb / 0x100) % 0x100, rgb % 0x100

SDL_FRect rectangle = { 0,0,0,0 };

namespace Graphics
{

	void WipeScreen(Colour rgb)
	{
		int width;
		int height;
		SDL_GetWindowSize(window, &width, &height);
		DrawRectangle(0, 0, width, height, rgb, 255);
	}

	void DrawRectangle(float x, float y, float w, float h, Colour rgb, int alpha)
	{
		rectangle.x = x;
		rectangle.y = y;
		rectangle.h = h;
		rectangle.w = w;

		SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), 255);
		SDL_RenderFillRectF(renderer, &rectangle);
	}

	void DrawLine(float x1, float y1, float x2, float y2, Colour rgb, int alpha)
	{
		SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);
		SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
	}

	void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha)
	{
		DrawLine(position1.x, position1.y, position2.x, position2.y, rgb, alpha);
	}

	void DrawLine(const Line& line, Colour rgb, int alpha)
	{
		DrawLine(line.startingPoint, line.endPoint, rgb, alpha);
	}

	void DrawEquilateralTriangle(const Vector2D& center, float sideLength, float angle)
	{
		//TODO: Добавить функцию
	}

	void DrawTriangle(const Triangle& triangle, Colour rgb, int alpha)
	{
		DrawLine(triangle.a, triangle.b, rgb, alpha);
		DrawLine(triangle.b, triangle.c, rgb, alpha);
		DrawLine(triangle.c, triangle.a, rgb, alpha);
	}

	void DrawCircle(float centreX, float centreY, float radius, Colour rgb, int alpha)
	{
		SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);

		float diameter = (radius * 2);

		float x = (radius - 1);
		float y = 0;
		float tx = 1;
		float ty = 1;
		float error = (tx - diameter);

		while (x >= y)
		{
			SDL_RenderDrawPointF(renderer, centreX + x, centreY - y);
			SDL_RenderDrawPointF(renderer, centreX + x, centreY + y);
			SDL_RenderDrawPointF(renderer, centreX - x, centreY - y);
			SDL_RenderDrawPointF(renderer, centreX - x, centreY + y);
			SDL_RenderDrawPointF(renderer, centreX + y, centreY - x);
			SDL_RenderDrawPointF(renderer, centreX + y, centreY + x);
			SDL_RenderDrawPointF(renderer, centreX - y, centreY - x);
			SDL_RenderDrawPointF(renderer, centreX - y, centreY + x);

			if (error <= 0)
			{
				++y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--x;
				tx += 2;
				error += (tx - diameter);
			}
		}
	}

	void DrawCircle(const Vector2D& centre, float radius, Colour rgb, int alpha)
	{
		DrawCircle(centre.x, centre.y, radius, rgb, alpha);
	}

	void RenderFrame()
	{
		SDL_RenderPresent(renderer);
	}

	

}
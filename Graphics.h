/****************************************************************************
 *  \file Graphics.h
 *  \brief
 *      - Интерфейс различных графических функций, обертки для SDL функций
 *  \author Рощин Константин
*****************************************************************************/
#pragma once

#include "Vector2D.h"
#include "Shapes.h"

typedef int Colour;

namespace Graphics //!< поле с графическими функциями
{

	//!Заливает экран цветом
	void WipeScreen(Colour rgb);

	//!Рисует прямоугольник
	void DrawRectangle(float x, float y, float h, float w, Colour rgb, int alpha);
	
	//!Рисует линию
	void DrawLine(float x1, float y1, float x2, float y2, Colour rgb, int alpha);

	//!Рисует линию
	void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha);

	//!Рисует линию
	void DrawLine(const Line& line, Colour rgb, int alpha);

	//!Рисует треугольник
	void DrawTriangle(const Triangle& triangle, Colour rgb, int alpha);

	//!Рисует круг
	void DrawCircle(float centreX, float centreY, float radius, Colour rgb, int alpha);

	//!Рисует круг
	void DrawCircle(const Vector2D& centre, float radius, Colour rgb, int alpha);

	//!Выводит кадр на экран
	void RenderFrame();
}
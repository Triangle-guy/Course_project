#pragma once

#include "Vector2D.h"
#include "Shapes.h"

typedef int Colour;

namespace Graphics
{

	void WipeScreen(Colour rgb);

	void DrawRectangle(float x, float y, float h, float w, Colour rgb, int alpha);
	
	void DrawLine(float x1, float y1, float x2, float y2, Colour rgb, int alpha);

	void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha);

	void DrawLine(const Line& line, Colour rgb, int alpha);

	void DrawEquilateralTriangle(const Vector2D& center, float sideLength, float angle);

	void DrawTriangle(const Triangle& triangle, Colour rgb, int alpha);

	void DrawCircle(float centreX, float centreY, float radius, Colour rgb, int alpha);

	void DrawCircle(const Vector2D& centre, float radius, Colour rgb, int alpha);

	void RenderFrame();
}
/****************************************************************************
 *  \file Graphics.cpp
 *  \brief
 *      - Имплементация различных графических функций, обертки для SDL функций
 *  \author Рощин Константин
*****************************************************************************/

#include "main.h"
#include "Graphics.h"

#define SPLIT_COLOUR(rgb) rgb / 0x10000, (rgb / 0x100) % 0x100, rgb % 0x100

SDL_FRect rectangle = { 0,0,0,0 }; //!< Прямоугольник

namespace Graphics //!< Поле графических функций
{

  /*!*************************************************************************
  void WipeScreen(Colour rgb)

  \brief
    Закрашивает экран цветом
  \param rgb
    Цвет, которым мы хотим закрасить экран

***************************************************************************/
  void WipeScreen(Colour rgb)
  {
    int width;
    int height;
    SDL_GetWindowSize(window, &width, &height);
    DrawRectangle(0, 0, width, height, rgb, 255);
  }

  /*!*************************************************************************
  void (float x, float y, float w, float h, Colour rgb, int alpha)

  \brief
    Рисуер прямоугольник
  \param x
    X-координата
  \param y
    Y-координата
  \param w
    Длина одной стороны
  \param h
    Длина второй стороны
  \param rgb
    Цвет
  \param alpha
    Прозрачность

***************************************************************************/
  void DrawRectangle(float x, float y, float w, float h, Colour rgb, int alpha)
  {
    rectangle.x = x;
    rectangle.y = y;
    rectangle.h = h;
    rectangle.w = w;

    SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), 255);
    SDL_RenderFillRectF(renderer, &rectangle);
  }

  /*!*************************************************************************
  void DrawLine(float x1, float y1, float x2, float y2, Colour rgb, int alpha)

  \brief
    Рисуер прямоугольник
  \param x1
    первая X-координата
  \param y1
    первая Y-координата

  \param x2
    вторая X-координата
  \param y2
    вторая Y-координата
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
  void DrawLine(float x1, float y1, float x2, float y2, Colour rgb, int alpha)
  {
    SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);
    SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
  }

  /*!*************************************************************************
  void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha)

  \brief
    Рисует прямоугольник
  \param position1
    Координата начала
  \param position1
    Координата конца
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
  void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha)
  {
    DrawLine(position1.x, position1.y, position2.x, position2.y, rgb, alpha);
  }

  /*!*************************************************************************
  void DrawLine(const Vector2D& position1, const Vector2D& position2, Colour rgb, int alpha)

  \brief
    Рисует прямоугольник
  \param line
    Линия, которую мы рисуем
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
  void DrawLine(const Line& line, Colour rgb, int alpha)
  {
    DrawLine(line.startingPoint, line.endPoint, rgb, alpha);
  }


  /*!*************************************************************************
  void DrawTriangle(const Triangle& triangle, Colour rgb, int alpha)

  \brief
    Рисует треугольник
  \param triangle
    Треугольник, которую мы рисуем
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
  void DrawTriangle(const Triangle& triangle, Colour rgb, int alpha)
  {
    DrawLine(triangle.a, triangle.b, rgb, alpha);
    DrawLine(triangle.b, triangle.c, rgb, alpha);
    DrawLine(triangle.c, triangle.a, rgb, alpha);
  }

  /*!*************************************************************************
  void DrawCircle(float centreX, float centreY, float radius, Colour rgb, int alpha)

  \brief
    Рисует круг
  \param centreX
    Х-координата центра
  \param centreY
    Y-координата центра
  \param radius
    Радиус круга
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
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

  /*!*************************************************************************
  void DrawCircle(const Vector2D& centre, float radius, Colour rgb, int alpha)

  \brief
    Рисует круг
  \param centre
    координаты центра
  \param radius
    Радиус круга
  \param rgb
    Цвет
  \param alpha
    Прозрачность

  ***************************************************************************/
  void DrawCircle(const Vector2D& centre, float radius, Colour rgb, int alpha)
  {
    DrawCircle(centre.x, centre.y, radius, rgb, alpha);
  }
  /*!*************************************************************************
  void RenderFrame()

  \brief
    Рисует кадр

  ***************************************************************************/
  void RenderFrame()
  {
    SDL_RenderPresent(renderer);
  }



}
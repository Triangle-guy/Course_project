#include "Main.h"
#include <vector>
#include "GameLoop.h"

#define SPLIT_COLOUR(rgb) rgb / 0x10000, (rgb / 0x100) % 0x100, rgb % 0x100

typedef int Colour;
extern RendererPtr renderer = nullptr;

extern WindowPtr window = nullptr;

extern ScreenSurfacePtr screenSurface = nullptr;

SDL_FRect rectangle;


/* EventHandler.cpp */
namespace EventHandler
{
	std::vector<SDL_Event> events;
	std::vector<SDL_Event>::iterator eventVectorIterator;
	SDL_Event eventTemp;

	void InitEvents()
	{
		while (SDL_PollEvent(&eventTemp))
		{
			events.push_back(eventTemp);
		}
		eventVectorIterator = events.begin();
	}

	void ShutdownEvents()
	{
		events.erase(events.begin(), events.end());
	}

	bool KeyPressed(SDL_Scancode key)
	{
		for (eventVectorIterator = events.begin(); eventVectorIterator < events.end(); eventVectorIterator++)
		{
			if ((*eventVectorIterator).type == SDL_KEYDOWN && (*eventVectorIterator).key.keysym.sym == SDL_GetKeyFromScancode(key))
			{
				events.erase(eventVectorIterator);
				return true;
			}
		}
		return false;
	}
}


/* Graphics.cpp */
namespace Graphics
{

	void WipeScreen(Colour rgb)
	{
		int width;
		int height;
		SDL_GetWindowSize(window, &width, &height);
		rectangle.x = 0;
		rectangle.y = 0;
		rectangle.w = width;
		rectangle.h = height;

		SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), 255);
		SDL_RenderFillRectF(renderer, &rectangle);
	}

}


/*main.cpp*/
int main(int argc, char* argv[])
{

	GameLoopInit();

	GameLoopUpdate();

	GameLoopShutdown();

	return 0;
}


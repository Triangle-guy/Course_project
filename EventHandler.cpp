#include "main.h"
#include "EventHandler.h"
#include <vector>


std::vector<SDL_Event> events;
std::vector<SDL_Event>::iterator eventVectorIterator;
SDL_Event eventTemp;

namespace EventHandler
{
	

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

	bool KeyIsDown(SDL_Scancode key)
	{
		const Uint8* keyState = SDL_GetKeyboardState(NULL);

		if (keyState[key])
		{
			return true;
		}
		return false;
	}
}
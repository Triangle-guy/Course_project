#include "main.h"
#include "GameLoop.h"
#include "Graphics.h"
#include "EventHandler.h"

#include <vector>

extern RendererPtr renderer = nullptr;

extern WindowPtr window = nullptr;

extern ScreenSurfacePtr screenSurface = nullptr;

int main(int argc, char* argv[])
{

	GameLoopInit();

	GameLoopUpdate();

	GameLoopShutdown();

	return 0;
}


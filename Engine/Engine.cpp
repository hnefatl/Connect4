#include "Engine.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Error.h"

bool EngineInit()
{
	if (!ErrorInit())
		return false;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		ErrorExit("SDL Init error", SDL_GetError(), false);

	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)))
		ErrorExit("IMG Init error", IMG_GetError(), false);

	if (TTF_Init() != 0)
		ErrorExit("TTF Init error", TTF_GetError(), false);

	return true;
}

void EngineQuit()
{
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
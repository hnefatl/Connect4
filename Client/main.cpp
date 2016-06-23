#include <iostream>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Window.h"
#include "Error.h"

int main(int argc, char *argv[])
{
	if (!InitError())
		return -1;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		ErrorExit("SDL Init error", SDL_GetError());

	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)))
		ErrorExit("IMG Init error", IMG_GetError());

	if (TTF_Init() != 0)
		ErrorExit("TTF Init error", TTF_GetError());


	Window Window("", 640, 480);

	if (!Window.Init())
		ErrorExit("Failed to create Window", SDL_GetError());

	SDL_Renderer *Renderer = Window.GetRenderer(-1, SDL_RENDERER_ACCELERATED);
	if (Renderer == nullptr)
		ErrorExit("Failed to create Renderer", SDL_GetError());


	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	return 0;
}
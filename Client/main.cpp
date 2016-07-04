#include <iostream>
#include <fstream>

#include <Engine.h>
#include <Window.h>
#include <Error.h>
#include <TextureManager.h>

#include <SDL.h>
#include <GL.h>

#include <list>
#include <time.h>


int main(int argc, char *argv[])
{
	if (!EngineInit())
		return -1;

	Window Window("Blah", 1366, 768);

	if (!Window.Init(false, false, false))
		ErrorExit("Failed to create Window", SDL_GetError(), -1);





	Window.~Window();
	EngineQuit();

	return 0;
}
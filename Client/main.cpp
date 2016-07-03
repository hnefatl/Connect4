#include <iostream>
#include <fstream>

#include <Engine/Engine.h>
#include <Engine/Window.h>
#include <Engine/Error.h>


int main(int argc, char *argv[])
{
	if (!EngineInit())
		return -1;

	Window Window("", 640, 480);

	if (!Window.Init())
		ErrorExit("Failed to create Window", SDL_GetError(), -1);



	EngineQuit();

	return 0;
}
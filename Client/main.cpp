#include <iostream>
#include <fstream>

#include <Engine.h>
#include <Window.h>
#include <Error.h>
#include <TextureManager.h>

#include <GL.h>


int main(int argc, char *argv[])
{
	if (!EngineInit())
		return -1;

	Window Window("", 640, 480);

	if (!Window.Init(false, false, false))
		ErrorExit("Failed to create Window", SDL_GetError(), -1);

	TextureManager Man(Immediate);
	Texture t = Man.Load(TextureSettings("Test.png"));



	EngineQuit();

	return 0;
}
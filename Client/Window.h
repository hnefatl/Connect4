#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Window
{
protected:
	SDL_Window *Inner;
	SDL_Surface *Surface;

	unsigned int Width;
	unsigned int Height;

	std::string Title;

public:
	Window(const std::string &Title, const unsigned int Width, const unsigned int Height);
	~Window();

	std::string GetTitle() const;
	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	const SDL_Window *const GetWindow() const;

	bool Init();

	SDL_Renderer *GetRenderer(const int Index, const SDL_RendererFlags Flags) const;
};

#endif
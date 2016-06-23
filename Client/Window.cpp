#include "Window.h"


Window::Window(const std::string &Title, const unsigned int Width, const unsigned int Height)
	: Width(Width), Height(Height), Title(Title)
{
}
Window::~Window()
{
	SDL_FreeSurface(Surface);
	SDL_DestroyWindow(Inner);
}


std::string Window::GetTitle() const
{
	return Title;
}
unsigned int Window::GetWidth() const
{
	return Width;
}
unsigned int Window::GetHeight() const
{
	return Height;
}

const SDL_Window *const Window::GetWindow() const
{
	return Inner;
}

bool Window::Init()
{
	SDL_Window *Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
	if (Window == nullptr)
		return false;

	return true;
}

SDL_Renderer *Window::GetRenderer(const int Index, const SDL_RendererFlags Flags) const
{
	return SDL_CreateRenderer(Inner, Index, Flags);
}
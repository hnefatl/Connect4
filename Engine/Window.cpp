#include "Window.h"

#include "GL.h"

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

bool Window::Init(const bool Borderless, const bool Fullscreen, const bool MouseCaptured)
{
	Uint32 Flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
	if (Borderless)
		Flags |= SDL_WINDOW_BORDERLESS;
	if (Fullscreen)
		Flags |= SDL_WINDOW_FULLSCREEN;
	if (MouseCaptured)
		Flags |= SDL_WINDOW_MOUSE_CAPTURE;

	SDL_Window *Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, Flags);
	if (Window == nullptr)
		return false;

	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, Width, Height);

	return true;
}
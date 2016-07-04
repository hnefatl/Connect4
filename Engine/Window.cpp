#include "Window.h"

#include "GL.h"
#include "Error.h"

Window::Window(const std::string &Title, const unsigned int Width, const unsigned int Height)
	: Width(Width), Height(Height), Title(Title)
{
}
Window::~Window()
{
	SDL_GL_DeleteContext(Context);
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

SDL_Window *Window::GetWindow() const
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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	Inner = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, Flags);
	if (Inner == nullptr)
		return false;

	Context = SDL_GL_CreateContext(Inner);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, Width, Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, Width, Height, 0.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);

	return true;
}
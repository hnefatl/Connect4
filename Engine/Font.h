#ifndef _FONT_H
#define _FONT_H

#include <SDL_ttf.h>

class Font
{
public:
	TTF_Font *Inner;
	unsigned int Size;

	Font();
	Font(TTF_Font *Font, const unsigned int Size);
};

#endif
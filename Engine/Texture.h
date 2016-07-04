#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "GL.h"

class Texture
{
public:
	GLuint Inner;
	unsigned int Width, Height;
	
	Texture();
	Texture(const GLuint Texture, const unsigned int Width, const unsigned int Height);
};

#endif
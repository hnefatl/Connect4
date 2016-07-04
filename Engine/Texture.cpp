#include "Texture.h"

Texture::Texture()
	:Texture(0, 0, 0)
{
}
Texture::Texture(const GLuint Texture, const unsigned int Width, const unsigned int Height)
	: Inner(Texture), Width(Width), Height(Height)
{
}
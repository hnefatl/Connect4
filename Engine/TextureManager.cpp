#include "TextureManager.h"

#include <SDL_image.h>

TextureManager::TextureManager(const UnloadBehaviour Behaviour)
	: AssetManager(Behaviour)
{
}


std::string TextureManager::GetKey(const TextureSettings &Settings) const
{
	return Settings.Path;
}
Texture *TextureManager::LoadAsset(const TextureSettings &Settings)
{
	SDL_Surface *Orig = IMG_Load(Settings.Path.c_str()); // Load as a surface
	if (Orig == nullptr)
		return nullptr;

	Texture *t = nullptr;
	glGenTextures(1, t);
	glBindTexture(GL_TEXTURE_2D, *t);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Orig->w, Orig->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Orig->pixels);

	SDL_FreeSurface(Orig);

	return t;
}
void TextureManager::DestroyAsset(Texture *Texture)
{
	glDeleteTextures(1, Texture);
}

#include "TextureManager.h"

#include <SDL_image.h>

#include "Error.h"

TextureManager::TextureManager(const std::string &AssetDir, const UnloadBehaviour Behaviour)
	: AssetManager(AssetDir, Behaviour)
{
}


std::string TextureManager::GetKey(const TextureSettings &Settings) const
{
	return AssetDir + '/' + Settings.Path;
}
Texture *TextureManager::LoadAsset(const TextureSettings &Settings)
{
	SDL_Surface *Orig = IMG_Load((AssetDir + '/' + Settings.Path).c_str()); // Load as a surface
	if (Orig == nullptr)
		return nullptr;

	Texture *t = new Texture(0, Orig->w, Orig->h);
	glGenTextures(1, &t->Inner);

	glBindTexture(GL_TEXTURE_2D, t->Inner);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Orig->w, Orig->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Orig->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_FreeSurface(Orig);

	return t;
}
void TextureManager::DestroyAsset(Texture *Texture)
{
	glDeleteTextures(1, &Texture->Inner);
	delete Texture;
}

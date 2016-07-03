#include "TextureManager.h"

#include <SDL_image.h>

TextureManager::TextureManager(SDL_Renderer *const Renderer, const UnloadBehaviour Behaviour)
	: AssetManager(Behaviour), Renderer(Renderer)
{
}


std::string TextureManager::GetKey(const TextureSettings &Settings)
{
	return Settings.Path;
}
SDL_Texture *TextureManager::LoadAsset(const TextureSettings &Settings)
{
	SDL_Surface *Orig = IMG_Load(Settings.Path.c_str()); // Load as a surface
	if (Orig == nullptr)
		return nullptr;

	SDL_Texture *Texture = SDL_CreateTextureFromSurface(Renderer, Orig); // Make texture
	SDL_FreeSurface(Orig);

	return Texture;
}
void TextureManager::DestroyAsset(SDL_Texture *Texture)
{
	SDL_DestroyTexture(Texture);
}

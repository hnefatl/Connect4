#include "TextureManager.h"

#include <SDL_image.h>

TextureManager::TextureManager(SDL_Renderer *const Renderer, const UnloadBehaviour Behaviour)
	: AssetManager(Behaviour), Renderer(Renderer)
{
}

void TextureManager::DestroyAsset(SDL_Texture *Texture)
{
	SDL_DestroyTexture(Texture);
}

SDL_Texture *TextureManager::LoadAsset(const std::string &Path)
{
	SDL_Surface *Orig = IMG_Load(Path.c_str()); // Load as a surface
	if (Orig == nullptr)
		return nullptr;

	SDL_Texture *Texture = SDL_CreateTextureFromSurface(Renderer, Orig); // Make texture
	SDL_FreeSurface(Orig);

	return Texture;
}
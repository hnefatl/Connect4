#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SDL.h>

#include "AssetManager.h"


class TextureManager
	: public AssetManager<SDL_Texture>
{
protected:
	SDL_Renderer *const Renderer;
	
	SDL_Texture *LoadAsset(const std::string &Path);
	void DestroyAsset(SDL_Texture *Texture);
public:
	TextureManager(SDL_Renderer *const Renderer, const UnloadBehaviour Behaviour);
};

#endif
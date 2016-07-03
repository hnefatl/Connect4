#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SDL.h>

#include "AssetManager.h"

class TextureSettings
	: public AssetSettings
{
public:
	std::string Path;
};

class TextureManager
	: public AssetManager<SDL_Texture, std::string>
{
protected:
	SDL_Renderer *const Renderer;
	
	std::string GetKey(const TextureSettings &Settings);
	SDL_Texture *LoadAsset(const TextureSettings &Settings);
	void DestroyAsset(SDL_Texture *Texture);
public:
	TextureManager(SDL_Renderer *const Renderer, const UnloadBehaviour Behaviour);

};

#endif
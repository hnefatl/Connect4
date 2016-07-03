#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <SDL_ttf.h>

#include "AssetManager.h"

class FontSettings
	: public AssetSettings
{
public:
	std::string Path;
	unsigned int Size;
};

class FontManager
	: public AssetManager<TTF_Font, std::string>
{
protected:

	std::string GetKey(const FontSettings &Settings) const;
	TTF_Font *LoadAsset(const FontSettings &Settings);
	void DestroyAsset(TTF_Font *Texture);
public:
	FontManager(const UnloadBehaviour Behaviour);

};

#endif
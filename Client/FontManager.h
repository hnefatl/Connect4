#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <SDL_ttf.h>

#include "AssetManager.h"

class FontManager
	: public AssetManager<TTF_Font>
{
protected:
	unsigned int FontLoadSize;

	TTF_Font *LoadAsset(const std::string &Path);
	void DestroyAsset(TTF_Font *Texture);
public:
	FontManager(const UnloadBehaviour Behaviour);

	unsigned int GetFontLoadSize() const;
	void SetFontLoadSize(const unsigned int FontLoadSize);
};

#endif
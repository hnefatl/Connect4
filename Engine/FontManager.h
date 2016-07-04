#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <SDL_ttf.h>

#include "AssetManager.h"
#include "Font.h"

class FontSettings
{
public:
	std::string Path;
	unsigned int Size;

	FontSettings(const std::string &Path, const unsigned int Size)
		: Path(Path), Size(Size)
	{
	}
};

class FontManager
	: public AssetManager<Font, std::string, FontSettings>
{
protected:

	std::string GetKey(const FontSettings &Settings) const;
	Font *LoadAsset(const FontSettings &Settings);
	void DestroyAsset(Font *Texture);
public:
	FontManager(const std::string &AssetDir, const UnloadBehaviour Behaviour);

};

#endif
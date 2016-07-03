#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SDL.h>

#include "AssetManager.h"
#include "Texture.h"

class TextureSettings
{
public:
	std::string Path;

	TextureSettings(const std::string &Path)
		:Path(Path)
	{
	}
};

class TextureManager
	: public AssetManager<Texture, std::string, TextureSettings>
{
protected:
	std::string GetKey(const TextureSettings &Settings) const;
	Texture *LoadAsset(const TextureSettings &Settings);
	void DestroyAsset(Texture *Texture);

public:
	TextureManager(const UnloadBehaviour Behaviour);

};

#endif
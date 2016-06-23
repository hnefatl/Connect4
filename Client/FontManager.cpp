#include "FontManager.h"

FontManager::FontManager(const UnloadBehaviour Behaviour)
	: AssetManager(Behaviour)
{
}


std::string FontManager::GetKey(const FontSettings &Settings) const
{
	return Settings.Path + ":" + SDL_uitoa(Settings.Size, nullptr, 10);
}
TTF_Font *FontManager::LoadAsset(const FontSettings &Settings)
{
	return TTF_OpenFont(Settings.Path.c_str(), Settings.Size);
}
void FontManager::DestroyAsset(TTF_Font *Font)
{
	TTF_CloseFont(Font);
}
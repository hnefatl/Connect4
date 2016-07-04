#include "FontManager.h"

FontManager::FontManager(const std::string &AssetDir, const UnloadBehaviour Behaviour)
	: AssetManager(AssetDir, Behaviour)
{
}


std::string FontManager::GetKey(const FontSettings &Settings) const
{
	return AssetDir + '/' + Settings.Path + ":" + SDL_uitoa(Settings.Size, nullptr, 10);
}
Font *FontManager::LoadAsset(const FontSettings &Settings)
{
	return new Font(TTF_OpenFont(Settings.Path.c_str(), Settings.Size), Settings.Size);
}
void FontManager::DestroyAsset(Font *Font)
{
	TTF_CloseFont(Font->Inner);
	delete Font;
}
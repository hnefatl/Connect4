#include "FontManager.h"

FontManager::FontManager(const UnloadBehaviour Behaviour)
	: AssetManager(Behaviour)
{
}


TTF_Font *FontManager::LoadAsset(const std::string &Path)
{
	return TTF_OpenFont(Path.c_str(), FontLoadSize);
}
void FontManager::DestroyAsset(TTF_Font *Font)
{
	TTF_CloseFont(Font);
}

unsigned int FontManager::GetFontLoadSize() const
{
	return FontLoadSize;
}
void FontManager::SetFontLoadSize(const unsigned int FontLoadSize)
{
	this->FontLoadSize = FontLoadSize;
}
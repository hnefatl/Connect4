#include "Font.h"

Font::Font()
	:Font(nullptr, 0)
{
}
Font::Font(TTF_Font *Font, const unsigned int Size)
	: Inner(Font), Size(Size)
{
}
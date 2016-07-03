#include "Error.h"

bool ErrorInit(const std::string &LogPath)
{
	if (ErrorInited)
		return true;
	try
	{
		std::ofstream Log(LogPath);
		if (!Log.good())
			return false;
		std::cerr.rdbuf(Log.rdbuf());
	}
	catch (...)
	{
		return false;
	}

	ErrorInited = true;
	return true;
}
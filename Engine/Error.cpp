#include "Error.h"

#include <iostream>

bool ErrorInit(const std::string &LogPath)
{
	try
	{
		Out = new std::ofstream(LogPath);
		if (!Out->good())
			return false;
		Log("Opened");
	}
	catch (...)
	{
		return false;
	}

	return true;
}
void ErrorQuit()
{
	Out->close();
	Out = nullptr;
}
#ifndef _ERROR_H
#define _ERROR_H

#include <iostream>
#include <fstream>
#include <string>

static bool ErrorInited = false;

#define Error(Message, ErrorDetails) if(ErrorInited) std::cerr << Message << std::endl << "Error: " << ErrorDetails << std::endl; 

#define ErrorExit(Message, ErrorDetails, Return) Error(Message, ErrorDetails); return Return;


bool ErrorInit(const std::string &LogPath = "Log.txt");

#endif
#ifndef _ERROR_H
#define _ERROR_H

#include <iostream>
#include <fstream>
#include <string>


static std::ofstream *Out;

bool ErrorInit(const std::string &LogPath = "Log.txt");
void ErrorQuit();

#define Error(Message, Details) { if(Out != nullptr) { (*Out) << Message << std::endl << "Error: " << Details << std::endl; Out->flush(); } }
#define Log(Message) { if(Out != nullptr) { (*Out) << Message << std::endl; Out->flush(); } }


#define ErrorExit(Message, ErrorDetails, Return) { Error(Message, ErrorDetails); return Return; }


#endif
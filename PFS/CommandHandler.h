#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "FileSystem.h"

class CommandHandler{

protected:
	FileSystem* file_system;

public:
	CommandHandler(FileSystem* file_system) : file_system(file_system) {}
	~CommandHandler() {}

	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream &stream) = 0;
	virtual void print_help(std::ostream& stream) { stream << "Not impliments" << std::endl; };
};


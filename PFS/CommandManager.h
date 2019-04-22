#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "CommandHandler.h"
#include "Utils.h"

class CommandManager{
	
	std::map<std::string, CommandHandler*> commands;

public:
	CommandManager();
	~CommandManager();

	void register_handler(std::string command, CommandHandler* handler);
	void delete_handler(std::string command);

	bool process_command(std::string command, std::ostream &out);
};


#pragma once
#include "CommandHandler.h"

class AddUserCommand: public CommandHandler{
public:
	AddUserCommand(FileSystem *file_system);
	~AddUserCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
};


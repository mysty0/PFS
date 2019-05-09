#pragma once
#include "CommandHandler.h"

class CreateFileCommand :
	public CommandHandler
{
public:
	CreateFileCommand(FileSystem* file_system);
	~CreateFileCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
	void print_help(std::ostream& out) override;
};


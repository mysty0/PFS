#pragma once
#include "CommandHandler.h"


class ReadFileCommand :
	public CommandHandler
{
public:
	ReadFileCommand(FileSystem* file_system);
	~ReadFileCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
	void print_help(std::ostream& out) override;
};


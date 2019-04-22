#pragma once
#include "CommandHandler.h"
class MakeDirectoryCommand :
	public CommandHandler
{
public:
	MakeDirectoryCommand(FileSystem* file_system);
	~MakeDirectoryCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;

};


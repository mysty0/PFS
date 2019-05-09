#pragma once
#include "CommandHandler.h"
class FileListCommand :
	public CommandHandler
{
public:
	FileListCommand(FileSystem* file_system);
	~FileListCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
	void print_help(std::ostream& out) override;
};


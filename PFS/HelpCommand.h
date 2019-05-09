#pragma once
#include "CommandHandler.h"
#include "CommandManager.h"
class HelpCommand : public CommandHandler{
	CommandManager* command_manager;
public:
	HelpCommand(FileSystem* file_system, CommandManager* cm);
	~HelpCommand();

	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
};


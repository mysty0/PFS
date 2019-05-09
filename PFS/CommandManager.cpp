#include "CommandManager.h"



CommandManager::CommandManager()
{
}


CommandManager::~CommandManager()
{
}

void CommandManager::register_handler(std::string command, CommandHandler* handler){
	if (commands.find(command) != commands.end()) return;
	commands[command] = handler;
}

void CommandManager::delete_handler(std::string command){
	commands.erase(command);
}

bool CommandManager::process_command(std::string command, std::ostream &out){
	std::vector<std::string> args;
	split_string(command, args);
	if (commands.find(args[0]) == commands.end()) return false;

	return commands[args[0]]->handle_command(args[0], args, out);
	
}

std::map<std::string, CommandHandler*> CommandManager::get_commands(){
	return commands;
}

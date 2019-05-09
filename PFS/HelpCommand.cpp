#include "HelpCommand.h"



HelpCommand::HelpCommand(FileSystem* file_system, CommandManager* cm) : CommandHandler::CommandHandler(file_system), command_manager(cm)
{
}


HelpCommand::~HelpCommand()
{
}

bool HelpCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& out){
	if (args.size() == 1) {
		out << "Usage:" << std::endl << "    help - command list" << std::endl << "    help [COMMAND] - help for command" << std::endl;
		out << "Commands: " << std::endl;
		for (const auto pair : command_manager->get_commands()) {
			out << "    " << pair.first << std::endl;
		}
	}
	else {
		std::map<std::string, CommandHandler*> commands = command_manager->get_commands();
		if (commands.find(args[1]) == commands.end()) {
			out << "Unknown command" << std::endl;
			return false;
		}
		commands.find(args[1])->second->print_help(out);
	}
	return true;
}

#include "AddUserCommand.h"


AddUserCommand::AddUserCommand(FileSystem* file_system): CommandHandler::CommandHandler(file_system)
{
}

AddUserCommand::~AddUserCommand()
{
}

bool AddUserCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() < 2) return false;
	file_system->get_user_table()->add_user(new User(args[1]));
	return true;
}

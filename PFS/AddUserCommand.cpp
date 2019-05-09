#include "AddUserCommand.h"


AddUserCommand::AddUserCommand(FileSystem* file_system): CommandHandler::CommandHandler(file_system)
{
}

AddUserCommand::~AddUserCommand()
{
}

bool AddUserCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() < 2) {
		print_help(stream);
		return false;
	}
	file_system->get_user_table()->add_user(new User(args[1]));
	stream << "User " << args[1] << " successfully added" << std::endl;
	return true;
}

void AddUserCommand::print_help(std::ostream& out){
	out << "Usage: " << std::endl << "    adduser [USERNAME] - add new user" << std::endl;
}

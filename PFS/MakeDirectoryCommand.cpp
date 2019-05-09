#include "MakeDirectoryCommand.h"



MakeDirectoryCommand::MakeDirectoryCommand(FileSystem* file_system) : CommandHandler::CommandHandler(file_system)
{
}


MakeDirectoryCommand::~MakeDirectoryCommand()
{
}

bool MakeDirectoryCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() == 1) return false;
	Path path;
	path = Path(args[1]);
	
	Directory* dir = file_system->get_directory(path, true);

	if (dir) return true;

	return false;
}

void MakeDirectoryCommand::print_help(std::ostream& out){
	out << "Usage:" << std::endl << "    mkdir PATH - create directory" << std::endl;
}

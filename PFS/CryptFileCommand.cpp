#include "CryptFileCommand.h"



CryptFileCommand::CryptFileCommand(FileSystem* file_system) : CommandHandler::CommandHandler(file_system)
{
}


CryptFileCommand::~CryptFileCommand()
{
}

bool CryptFileCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() == 1) return false;

	if (args.size() < 2) return false;
	File* file = file_system->get_file(Path(args[1]));
	if (file == nullptr) return false;

	AsymmetricCryptedFile crypted(*file);
	crypted.crypt(file_system->get_user_table());

	return true;
}

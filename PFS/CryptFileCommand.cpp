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
	if (args.size() == 4 && args[1] == "-d") {
		User* user = file_system->get_user_table()->get_user(args[2]);
		if (user == nullptr) return false;
		File* file = file_system->get_file(Path(args[3]));
		if (file == nullptr) return false;

		FileCryptor::decrypt_file(file, user);

		return true;
	}
	File* file = file_system->get_file(Path(args[1]));
	if (file == nullptr) return false;

	//AsymmetricCryptedFile crypted(*file);
	//crypted.crypt(file_system->get_user_table());
	FileCryptor::crypt_file(file, file_system->get_user_table());
	return true;
}

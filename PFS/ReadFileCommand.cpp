#include "ReadFileCommand.h"



ReadFileCommand::ReadFileCommand(FileSystem* file_system) : CommandHandler::CommandHandler(file_system)
{
}


ReadFileCommand::~ReadFileCommand()
{
}

bool ReadFileCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() < 2) return false;
	File* file = file_system->get_file(Path(args[1]));
	if (file == nullptr) return false;
	FileByteStream* fstream = (FileByteStream*)file->open(0);
	for (FileBytePointer i = 0; i < fstream->get_size(); ++i) stream << fstream->read(i);
	stream << std::endl;
	delete fstream;
	return true;
}

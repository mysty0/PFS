#include "CreateFileCommand.h"



CreateFileCommand::CreateFileCommand(FileSystem* file_system) : CommandHandler::CommandHandler(file_system)
{
}


CreateFileCommand::~CreateFileCommand()
{
}

bool CreateFileCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() == 1) return false;
	
	Path path = Path(args[1]);
	File* file = file_system->create_file(path.parent(), path.get_directories().back());
	if (!file) return false;
	if (args.size() > 2) {
		FileByteStream* stream = (FileByteStream*)file->open(0);
		stream->write(0, args[2].c_str(), args[2].size());
		delete stream;
	}

	return true;
}

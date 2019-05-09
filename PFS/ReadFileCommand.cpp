#include "ReadFileCommand.h"



ReadFileCommand::ReadFileCommand(FileSystem* file_system) : CommandHandler::CommandHandler(file_system)
{
}


ReadFileCommand::~ReadFileCommand()
{
}

bool ReadFileCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	if (args.size() < 2) return false;
	FileByteStream* fstream;
	if (args[1].find(':') != std::string::npos) {
		std::vector<std::string> path;
		split_string(args[1], path, ':');
		if (path.size() != 2) return false;
		File* file = file_system->get_file(Path(path[0]));
		if (file == nullptr) return false;
		fstream = (FileByteStream*)file->open_stream(path[1]);
		if (fstream == nullptr) return false;
		
	}
	else {
		File* file = file_system->get_file(Path(args[1]));
		if (file == nullptr) return false;
		fstream = (FileByteStream*)file->open(0);
	}
	stream << "Size: " << fstream->get_size() << " bytes" << std::endl;
	for (FileBytePointer i = 0; i < fstream->get_size(); ++i) stream << fstream->read(i);
	stream << std::endl;
	delete fstream;
	return true;
}

void ReadFileCommand::print_help(std::ostream& out){
	out << "Usage:" << std::endl << "    read PATH[:STREAMNAME] - read file" << std::endl;
}

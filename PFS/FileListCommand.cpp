#include "FileListCommand.h"


FileListCommand::FileListCommand(FileSystem* file_system): CommandHandler::CommandHandler(file_system)
{
}

FileListCommand::~FileListCommand()
{
}

bool FileListCommand::handle_command(std::string command, std::vector<std::string> args, std::ostream& stream){
	Path path;
	if (args.size() == 1) path = Path();
	else path = Path(args[1]);
	Directory *dir = file_system->get_directory(path, false);
	if (!dir) return false;
	
	DirectoryStream* dir_stream = (DirectoryStream*)dir->open(0);
	File** files = dir_stream->get_files();
	for (int i = 0; i < dir_stream->get_count(); ++i) stream << files[i]->get_name() << std::endl;
	//for(const)

	return true;
}

void FileListCommand::print_help(std::ostream& out){
	out << "Usage:" << std::endl << "    ls [PATH] - print list of files in directory" << std::endl;
}

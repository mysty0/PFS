#include "Directory.h"



Directory::Directory(Storage *storage, Path path): File(storage, path){
	files = std::map<FileId, File*>();
}


Directory::~Directory(){
	for (const std::pair<FileId, File*>& file : files) delete file.second;
	//File::~File();
}

bool Directory::create(){
	return true;
}

FileDataStream *Directory::open(char flags){
	return new DirectoryStream(&files);
}

File * Directory::find(std::string name, bool directory){
	for (const std::pair<FileId, File*> &file : files) if (file.second->get_name() == name && file.second->is_directory() == directory) return file.second;
	return nullptr;
}

bool Directory::is_directory() const{
	return true;
}

bool Directory::is_file_exists(File *file){
	return files.find(file->get_id()) != files.end();
}

bool Directory::is_file_exists(std::string file_name){
	for (const std::pair<FileId, File*> &iter : files) if (iter.second->get_name() == file_name) return true;
	return false;
}

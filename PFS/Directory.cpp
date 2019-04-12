#include "Directory.h"



Directory::Directory(Storage *storage): File(storage){
	files = std::map<FileId, File>();
}


Directory::~Directory(){
}

bool Directory::create(){
	return true;
}

FileDataStream Directory::open(char flags){
	return DirectoryStream(&files);
}

bool Directory::is_directory() const{
	return true;
}

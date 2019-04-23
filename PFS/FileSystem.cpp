#include "FileSystem.h"



FileSystem::FileSystem(): FileSystem(new Storage(1024, 64)){	
}

FileSystem::FileSystem(Storage* storage): storage(storage){
	Directory* dir = new Directory(storage, Path());
	dir->create();
	root_dir = dir;
}


FileSystem::~FileSystem(){
	delete root_dir;
}

Directory *FileSystem::get_directory(Path path, bool create_dirs) {
	Directory *dir = root_dir;
	for (std::string cur : path.get_directories()) {
		if (!dir->is_file_exists(cur)) {
			if (!create_dirs) return false;
			Directory *new_dir = new Directory(storage, path + cur);
			new_dir->set_name(cur);
			DirectoryStream *stream = (DirectoryStream*)dir->open(0);
			stream->add_file(new_dir);
			delete stream;
			dir = new_dir;
		}
		else dir = ((Directory*)dir->find(cur, true));
	}
	return dir;
}

File* FileSystem::get_file(Path path){
	DirectoryStream* stream = (DirectoryStream*)get_directory(path.parent(), true)->open(0);
	File* file = stream->get_file(path.get_directories().back());
	if (file) return file;
	return nullptr;
}

UserTable* FileSystem::get_user_table(){
	return &user_table;
}

Directory *FileSystem::create_directory(Path path, std::string name){
	Directory *dir = new  Directory(storage, path + name);
	dir->set_name(name);
	DirectoryStream *stream = (DirectoryStream*)get_directory(path, true)->open(0);
	stream->add_file(dir);
	delete stream;
	return dir;
}

void FileSystem::move(File *file, Path path){
	DirectoryStream *stream = (DirectoryStream*)get_directory(file->get_path(), true)->open(0);
	stream->delete_file(file);
	delete stream;
	stream = (DirectoryStream*)get_directory(path, true)->open(0);
	stream->add_file(file);
	delete stream;
	file->set_path(path);
}

void FileSystem::rename(File *file, std::string new_name){
	file->set_name(new_name);
}

void FileSystem::delete_file(File * file){
	DirectoryStream *stream = (DirectoryStream*)get_directory(file->get_path(), true)->open(0);
	stream->delete_file(file);
	delete stream;
	file->delete_file();
}

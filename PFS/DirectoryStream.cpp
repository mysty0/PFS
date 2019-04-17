#include "DirectoryStream.h"



DirectoryStream::DirectoryStream(std::map<FileId, File*>* files): files(files){
}


DirectoryStream::~DirectoryStream()
{
}

File ** DirectoryStream::get_files() const{
	File ** fls = new File*[files->size()];
	int i = 0;
	for (std::map<FileId, File*>::iterator it = files->begin(); it != files->end(); it++) fls[i++] = it->second;

	return fls;
}

unsigned int DirectoryStream::get_count() const{
	return files->size();
}

void DirectoryStream::add_file(File *file){
	files->insert(std::pair<FileId, File*>(file->get_id(), file));
}

void DirectoryStream::delete_file(std::string name){
	for (const std::pair<FileId, File*> &el : *files) if (el.second->get_name() == name) files->erase(el.first);
}

void DirectoryStream::delete_file(File * file){
	delete_file(file->get_id());
}

void DirectoryStream::delete_file(FileId id){
	files->erase(id);
}

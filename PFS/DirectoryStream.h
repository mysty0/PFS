#pragma once
#include <map>
#include <string>

#include "FileDataStream.h"
#include "FileTypedef.h"
#include "File.h"

class DirectoryStream :
	public FileDataStream {

	std::map<FileId, File*>* files;

public:
	DirectoryStream(std::map<FileId, File*>* files);
	~DirectoryStream();

	File** get_files() const;
	unsigned int get_count() const;
	void add_file(File *file);
	void delete_file(std::string name);
	void delete_file(File* file);
	void delete_file(FileId id);
	File* get_file(std::string name);
};

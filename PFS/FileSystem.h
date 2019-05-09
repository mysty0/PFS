#pragma once

#include <string>

#include "Storage.h"
#include "File.h"
#include "FileTypedef.h"
#include "Path.h"
#include "Directory.h"
#include "DirectoryStream.h"
#include "UserTable.h"

class FileSystem{
	Directory *root_dir;
	Storage *storage;

	UserTable user_table;

public:
	FileSystem();
	FileSystem(Storage *storage);
	~FileSystem();

	template <class T = File>
	T* create_file(Path path, std::string name) {
		DirectoryStream* stream = (DirectoryStream*)get_directory(path, true)->open(0);
		File* file = stream->get_file(name);
		if (file) return (T*)file;

		file = new T(storage, path);
		file->set_name(name);
		
		stream->add_file(file);
		delete stream;
		return (T*)file;
	}
	Directory *create_directory(Path path, std::string name);

	void move(File *file, Path path);
	void rename(File *file, std::string new_name);
	void delete_file(File *file);

	Directory *get_directory(Path path, bool create_dirs);
	File* get_file(Path path);

	UserTable* get_user_table();

	void wipe();
};

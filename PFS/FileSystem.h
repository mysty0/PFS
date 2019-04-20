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
	Storage storage;

	UserTable user_table;

public:
	FileSystem();
	~FileSystem();

	template <class T = File>
	T *create_file(Path path, std::string name);
	Directory *create_directory(Path path, std::string name);

	void move(File *file, Path path);
	void rename(File *file, std::string new_name);
	void delete_file(File *file);

	Directory *get_directory(Path path, bool create_dirs);

	UserTable* get_user_table();
};

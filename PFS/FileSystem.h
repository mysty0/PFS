#pragma once
#include <string>

#include "Storage.h"
#include "File.h"
#include "FileTypedef.h"
#include "Path.h"
#include "Directory.h"

class FileSystem{
	Directory *root_dir;
	Storage storage;

public:
	FileSystem();
	~FileSystem();

	File create_file(Path path, std::string name);
	Directory create_directory(Path path, std::string name);

	void move(FileId file, Path path);
	void rename(FileId file, std::string new_name);
	void detlete(FileId file);
};


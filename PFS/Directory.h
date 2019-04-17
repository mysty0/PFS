#pragma once
#include <map>
#include "FileTypedef.h"
#include "File.h"
#include "DirectoryStream.h"
#include "Storage.h"
#include "DirectoryPermissions.h"
class Directory: public File{
	std::map<FileId, File*> files;
	
public:
	Directory(Storage *storage, Path path);
	~Directory();

	bool create() override;
	FileDataStream *open(char flags) override;

	File* find(std::string name, bool directory = false);

	bool is_directory() const override;
	bool is_file_exists(File *file);
	bool is_file_exists(std::string file_name);
};

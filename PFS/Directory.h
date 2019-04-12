#pragma once
#include <map>
#include "FileTypedef.h"
#include "File.h"
#include "DirectoryStream.h"
#include "Storage.h"
#include "DirectoryPermissions.h"
class Directory: public File{
	std::map<FileId, File> files;
	
public:
	Directory(Storage *storage);
	~Directory();

	bool create() override;
	FileDataStream open(char flags) override;

	bool is_directory() const override;

};


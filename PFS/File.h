#pragma once
#include "Storage.h"
#include "FileDescriptor.h"
#include "FileDataStream.h"
#include "FileByteStream.h"
#include "FileTypedef.h"

#include <ctime>
#include <string>

class File{
	const FileSize default_file_size = 1;

	std::string name;
	
	std::time_t created_date;
	std::time_t modified_date;

	FileDescriptor descripor = NULL;
public:
	File(Storage * storage);
	~File();

	virtual bool create();

	virtual FileDataStream open(char flags);

	std::string get_name();
	void set_name(std::string name);
};


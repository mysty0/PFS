#pragma once
#include "Storage.h"
#include "FileDescriptor.h"
#include "FileDataStream.h"
#include "FileByteStream.h"
#include "FileTypedef.h"
#include "FilePermissions.h"

#include <ctime>
#include <string>

class File{
	const FileSize default_file_size = 1;

	std::string name;
	
	std::time_t created_date;
	std::time_t modified_date;

	FilePermissions *permissions;

	FileDescriptor descripor = NULL;
public:
	File(Storage * storage);
	~File();

	virtual bool create();

	virtual FileDataStream open(char flags);

	virtual bool is_directory() const;

	std::string get_name() const;
	void set_name(std::string name);

	std::time_t get_created_data() const;
	void set_created_data(std::time_t created_date);

	std::time_t get_modified_data() const;
	void set_modified_data(std::time_t modified_date);

	virtual void set_permissions(FilePermissions permissions);
	virtual FilePermissions get_permissions() const;

	FileId get_id() const;

};


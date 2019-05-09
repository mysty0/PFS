#pragma once
#include <string>

#include "FileDataStream.h"
#include "FileTypedef.h"
#include "FileDescriptor.h"

class FileByteStream :
	public FileDataStream
{
	FileDescriptor *descriptor;
public:
	FileByteStream(FileDescriptor * descriptor);
	~FileByteStream();

	bool write(FileBytePointer pointer, const char byte);
	bool write(FileBytePointer pointer, const char* bytes, StorageFileSize size);
	bool write_int(FileBytePointer pointer, int i);
	FileBytePointer write_string(FileBytePointer pointer, std::string str);

	char read(FileBytePointer pointer);
	char* read(FileBytePointer pointer, StorageFileSize size);
	int read_int(FileBytePointer pointer);
	int read_string(FileBytePointer pointer, std::string& str);

	FileSize get_size();
};


#pragma once
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

	bool write(FileBytePointer pointer, char byte);
	bool write(FileBytePointer pointer, char* bytes, StorageFileSize size);

	char read(FileBytePointer pointer);
	char* read(FileBytePointer pointer, StorageFileSize size);

	FileSize get_size();
};


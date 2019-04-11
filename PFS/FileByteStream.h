#pragma once
#include "FileDataStream.h"
#include "FileTypedef.h"

class FileByteStream :
	public FileDataStream
{
public:
	FileByteStream(FileDescriptor * descriptor);
	~FileByteStream();

	bool write(FileBytePointer pointer, char byte);
	bool write(FileBytePointer pointer, char* bytes, StorageFileSize size);

	char read(FileBytePointer pointer);
	char* read(FileBytePointer pointer, StorageFileSize size);
};


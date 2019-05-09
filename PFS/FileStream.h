#pragma once
#include "StorageChunk.h"
#include "FileDescriptor.h"
#include "FileByteStream.h"

class FileStream{
	StorageChunk* chunk;
	FileDescriptor descriptor;

public:
	FileStream(Storage* storage);
	~FileStream();

	FileByteStream* open();
	void erase();
};


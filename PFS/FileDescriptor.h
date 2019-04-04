#pragma once
#include "Storage.h"
#include "StorageTypedef.h"
#include "StorageChunk.h"

class FileDescriptor{
	Storage * storage;
	StorageChunk* root_chunk;
	StorageFileSize file_size;

public:
	FileDescriptor(Storage * storage);
	FileDescriptor(Storage * storage, StorageFileSize size);
	~FileDescriptor();

	bool create(StorageFileSize size);
	bool resize(StorageFileSize new_size);

	void delete_file();

	bool write(StoragePointer pointer, char byte);
	bool write(StoragePointer pointer, char *bytes, StorageFileSize len);

	char read(StoragePointer pointer);
	char* read(StoragePointer pointer, StorageFileSize len);

	bool is_created();

	StorageFileSize get_size();

};


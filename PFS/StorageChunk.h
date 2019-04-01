#pragma once
#include "StorageTypedef.h"


class StorageChunk{
public:
	StoragePointer pointer;
	StorageFileSize size;
	StorageChunk* next;

	StorageChunk() : StorageChunk(0, 0) {};
	StorageChunk(StorageFileSize size, StoragePointer pointer, StorageChunk* next = nullptr);
	
	~StorageChunk();

	void set_chain_size(StorageFileSize new_size, StorageFileSize chunk_size);
};

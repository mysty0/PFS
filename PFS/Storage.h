#pragma once
#include <map> 
#include "StorageChunk.h"
#include "ChunkStorage.h"
#include "MapChunkStorage.h"

class Storage {
	char* bytes;
	unsigned int storage_size;
	StorageFileSize chunk_size;
	unsigned int avalible_size;
	ChunkStorage *chunks;

	StoragePointer find_free_space();
	StorageChunk *allocate_chunk(unsigned int size);
	unsigned int delete_chain(StorageChunk * first);

public:
	Storage(unsigned int size, StorageFileSize chunk_size, ChunkStorage *chunk_storage = new MapChunkStorage());
	~Storage();

	StorageChunk* allocate(StorageFileSize size);
	void deallocate(StorageChunk* file);
	bool resize(StorageChunk * file, StorageFileSize new_size);

	char* get_storage() { return bytes; }
};


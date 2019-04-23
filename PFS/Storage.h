#pragma once
#include <map> 
#include "StorageChunk.h"
#include "ChunkStorage.h"
#include "MapChunkStorage.h"
#include "ByteStorage.h"
#include "VirtualByteStorage.h"

class Storage {
	ByteStorage* byte_storage;
	unsigned int storage_size;
	StorageFileSize chunk_size;
	unsigned int avalible_size;
	ChunkStorage *chunks;

	StoragePointer find_free_space();
	StorageChunk *allocate_chunk(unsigned int size);
	unsigned int delete_chain(StorageChunk * first);

public:
	Storage(StorageSize size, StorageFileSize chunk_size, ChunkStorage *chunk_storage = new MapChunkStorage()) : Storage(size, chunk_size, new VirtualByteStorage(size), chunk_storage){}
	Storage(StorageSize size, StorageFileSize chunk_size, ByteStorage* byte_storage, ChunkStorage *chunk_storage = new MapChunkStorage());
	~Storage();

	StorageChunk* allocate(StorageFileSize size);
	void deallocate(StorageChunk* file);
	bool resize(StorageChunk * file, StorageFileSize new_size);

	void read(StorageChunk * file, StoragePointer pointer, char * buffer, StorageFileSize size);
	bool write(StorageChunk * file, StoragePointer pointer, const char* bytes, StorageFileSize size);

	void wipe();
};


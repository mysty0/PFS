#pragma once
#include "StorageChunk.h"
#include "StorageTypedef.h"
class ChunkStorage {
public:
	ChunkStorage() {};
	virtual ~ChunkStorage() {}

	StorageChunk* operator[](StoragePointer pointer) { return get(pointer); }
	bool operator()(StoragePointer pointer) { return exist(pointer); }

	virtual StorageChunk* get(StoragePointer pointer) = 0;
	virtual StorageChunk* set(StoragePointer pointer, StorageChunk chunk) = 0;
	virtual bool exist(StoragePointer pointer) = 0;
	virtual bool is_empty() = 0;
	virtual void remove(StoragePointer pointer) = 0;
};
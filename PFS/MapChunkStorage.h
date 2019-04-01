#pragma once
#include "ChunkStorage.h"
#include <map> 

class MapChunkStorage :
	public ChunkStorage
{
private:
	std::map<StoragePointer, StorageChunk*> map;
public:
	MapChunkStorage();
	~MapChunkStorage();


	// Inherited via ChunkStorage
	virtual StorageChunk * get(StoragePointer pointer) override;
	virtual StorageChunk* set(StoragePointer pointer, StorageChunk chunk) override;

	virtual bool exist(StoragePointer pointer) override;
	virtual bool is_empty() override;
	virtual void remove(StoragePointer pointer) override;

};


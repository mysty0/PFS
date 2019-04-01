#include "MapChunkStorage.h"



MapChunkStorage::MapChunkStorage()
{
}


MapChunkStorage::~MapChunkStorage()
{
}

StorageChunk * MapChunkStorage::get(StoragePointer pointer){
	return map[pointer];
}

StorageChunk* MapChunkStorage::set(StoragePointer pointer, StorageChunk chunk){
	if (exist(pointer)) delete map[pointer];
	StorageChunk *point = new StorageChunk(chunk);
	map[pointer] = point;
	return point;
}

bool MapChunkStorage::exist(StoragePointer pointer){
	return map.find(pointer) != map.end();
}

bool MapChunkStorage::is_empty(){
	return map.empty();
}

void MapChunkStorage::remove(StoragePointer pointer){
	//StorageChunk* prev = get(pointer);
	map.erase(pointer);
	//delete prev;
}

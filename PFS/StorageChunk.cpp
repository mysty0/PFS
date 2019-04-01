#include "StorageChunk.h"


StorageChunk::StorageChunk(StorageFileSize size, StoragePointer pointer, StorageChunk* next): pointer(pointer), size(size), next(next){
}


StorageChunk::~StorageChunk(){
}

void StorageChunk::set_chain_size(StorageFileSize new_size, StorageFileSize chunk_size){
	StorageChunk *cur = this;
	StorageFileSize rem_size = new_size;
	while (cur) {
		cur->size = rem_size;
		rem_size -= chunk_size;
		cur = cur->next;
	}
}

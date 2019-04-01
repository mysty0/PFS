#include "Storage.h"


StoragePointer Storage::find_free_space() {
	if (chunks->is_empty()) return 1;
	for (StoragePointer pointer = 1; pointer < storage_size / chunk_size; ++pointer) {
		if (!chunks->exist(pointer)) return pointer;
	}
	return 0;
}

StorageChunk * Storage::allocate_chunk(unsigned int size) {
	StoragePointer free_pointer = find_free_space();
	if (free_pointer == 0) return nullptr;
	StorageChunk *chunk = chunks->set(free_pointer, StorageChunk(size, free_pointer));
	//chunks->set(free_pointer, *chunk)// = chunk;//.insert(std::pair<StoragePointer, StorageChunk*>(free_pointer, chunk));
	return chunk;
}

unsigned int Storage::delete_chain(StorageChunk * first){
	StorageChunk *cur = first;
	unsigned int count = 0;
	while (cur){
		StorageChunk *prev = cur;
		cur = cur->next;
		chunks->remove(prev->pointer);
		delete prev;
		++count;
	}
	return count;
}

Storage::Storage(unsigned int size, unsigned int chunk_size, ChunkStorage* chunk_storage) : storage_size(size), chunk_size(chunk_size), avalible_size(size), chunks(chunk_storage) {
	bytes = new char[size];
}


Storage::~Storage() {
	delete[] bytes;
}

StorageChunk * Storage::allocate(StorageFileSize size) {
	if (size > avalible_size) return nullptr;
	StorageChunk* first = allocate_chunk(size);
	if (!first) return nullptr;

	StorageChunk *cur = first;
	unsigned int chunk_count = size / chunk_size + (size % chunk_size == 0? 0 : 1);
	for (int i = 1; i < chunk_count; ++i) {
		cur->next = allocate_chunk(size - i*chunk_size);
		if (!cur->next) {
			delete_chain(first);
			return nullptr;
		}
		cur = cur->next;
	}
	avalible_size -= chunk_count * chunk_size;

	return first;
}

void Storage::deallocate(StorageChunk* file){
	unsigned int count = delete_chain(file);
	avalible_size -= count * chunk_size;
}

bool Storage::resize(StorageChunk * file, StorageFileSize new_size){
	if (file->size == new_size) return true;
	else if (file->size > new_size) {
		StorageFileSize rem_size = new_size;
		StorageChunk *cur = file;
		while (cur) {
			cur->size = rem_size;
			rem_size -= chunk_size;
			cur = cur->next;
			if (rem_size < chunk_size) {
				delete_chain(cur);
				break;
			}
		}
		return true;
	}
	else {
		StorageFileSize start_size = file->size;
		StorageFileSize rem_size = new_size;
		StorageChunk *cur = file;
		if (avalible_size < (new_size - cur->size)) return false;
		while (rem_size != 0) {
			cur->size = rem_size;
			if (rem_size <= chunk_size) break;
			rem_size -= chunk_size;
			if (!cur->next) {
				StorageChunk *rem_chunks = allocate(rem_size);
				if (!rem_chunks) {
					file->set_chain_size(start_size, chunk_size);
					return false;
				}
				cur->next = rem_chunks;
			}
			else cur = cur->next;
		}
		return true;
	}
	
}
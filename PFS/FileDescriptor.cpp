#include "FileDescriptor.h"



FileDescriptor::FileDescriptor(Storage * storage): storage(storage){
}

FileDescriptor::FileDescriptor(Storage * storage, StorageFileSize size) : storage(storage) {
	create(size);
}

FileDescriptor::FileDescriptor(Storage* storage, StorageChunk* root_chunk) : storage(storage) {
	this->root_chunk = root_chunk;
}



FileDescriptor::~FileDescriptor()
{
}

bool FileDescriptor::create(StorageFileSize size){
	StorageChunk * chunk = storage->allocate(size);
	if (!chunk) return false;
	root_chunk = chunk;
	
	return true;
}

bool FileDescriptor::resize(StorageFileSize new_size){
	if (!root_chunk) return false;
	bool res = storage->resize(root_chunk, new_size);
	if (!res) return false;

	return false;
}

void FileDescriptor::delete_file(){
	if (!root_chunk) return;
	storage->deallocate(root_chunk);
	root_chunk = nullptr;
}

bool FileDescriptor::write(StoragePointer pointer, const char byte){
	return write(pointer, &byte, 1);
}

bool FileDescriptor::write(StoragePointer pointer, const char * bytes, StorageFileSize len){
	if (!root_chunk) return false;
	return storage->write(root_chunk, pointer, bytes, len);
}

char FileDescriptor::read(StoragePointer pointer) const {
	if (!root_chunk) return '\0';
	char *res_arr = read(pointer, 1);
	char res = *res_arr;
	delete[] res_arr;
	return res;
}

char * FileDescriptor::read(StoragePointer pointer, StorageFileSize len) const {
	if (!root_chunk) return nullptr;
	char*res = new char[len];
	storage->read(root_chunk, pointer, res, len);
	return res;
}

bool FileDescriptor::is_created()  const {
	return root_chunk != nullptr;
}

StorageFileSize FileDescriptor::get_size()  const {
	return root_chunk->size;
}

StoragePointer FileDescriptor::get_pointer()  const {
	if (root_chunk == nullptr) return 0;
	return root_chunk->pointer;
}

Storage* FileDescriptor::get_storage() const{
	return storage;
}

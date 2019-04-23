#include "VirtualByteStorage.h"
#include <iostream>

VirtualByteStorage::VirtualByteStorage(StorageSize size){
	storage_size = size;
	bytes = new char[size];
}


VirtualByteStorage::~VirtualByteStorage(){
	delete[] bytes;
}

bool VirtualByteStorage::write(StoragePointer pointer, const char * bytes, StorageFileSize size){
	if (pointer + size >= storage_size) return false;
	std::memcpy(this->bytes + pointer, bytes, size);
	return true;
}

void VirtualByteStorage::read(StoragePointer pointer, char* buffer, StorageFileSize size){
	if (pointer + size >= storage_size) return;
	std::memcpy(buffer, &bytes[pointer], size);
}

void VirtualByteStorage::wipe(){
	std::memset(bytes, 0, storage_size);
}

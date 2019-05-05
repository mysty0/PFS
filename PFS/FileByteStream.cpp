#include "FileByteStream.h"



FileByteStream::FileByteStream(FileDescriptor * descriptor): descriptor(descriptor){
	this->descriptor = descriptor;
}


FileByteStream::~FileByteStream()
{
}

bool FileByteStream::write(FileBytePointer pointer, const char byte){
	return descriptor->write(pointer, byte);
}

bool FileByteStream::write(FileBytePointer pointer, const char * bytes, StorageFileSize size){
	return descriptor->write(pointer, bytes, size);
}



bool FileByteStream::write_int(FileBytePointer pointer, int val){
	const int size = 4;
	for (int i = 0; i < size; ++i) if (!write(pointer+i, val << (size - 1 - i) * size >> (size - 1 + i) * size)) return false;
	return true;
}

FileBytePointer FileByteStream::write_string(FileBytePointer pointer, std::string str){
	write_int(pointer, str.size());
	write(pointer + 4, str.c_str(), str.size());
	return pointer + 4 + str.size();
}

char FileByteStream::read(FileBytePointer pointer){
	return descriptor->read(pointer);
}

char * FileByteStream::read(FileBytePointer pointer, StorageFileSize size){
	return descriptor->read(pointer, size);
}

FileSize FileByteStream::get_size(){
	return descriptor->get_size();
}

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

char FileByteStream::read(FileBytePointer pointer){
	return descriptor->read(pointer);
}

char * FileByteStream::read(FileBytePointer pointer, StorageFileSize size){
	return descriptor->read(pointer, size);
}

FileSize FileByteStream::get_size(){
	return descriptor->get_size();
}

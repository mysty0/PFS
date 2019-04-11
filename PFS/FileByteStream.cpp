#include "FileByteStream.h"



FileByteStream::FileByteStream(FileDescriptor * descriptor): FileDataStream(descriptor){
	this->descriptor = descriptor;
}


FileByteStream::~FileByteStream()
{
}

bool FileByteStream::write(FileBytePointer pointer, char byte){
	return descriptor->write(pointer, byte);
}

bool FileByteStream::write(FileBytePointer pointer, char * bytes, StorageFileSize size){
	return descriptor->write(pointer, bytes, size);
}

char FileByteStream::read(FileBytePointer pointer){
	return descriptor->read(pointer);
}

char * FileByteStream::read(FileBytePointer pointer, StorageFileSize size){
	return descriptor->read(pointer, size);
}

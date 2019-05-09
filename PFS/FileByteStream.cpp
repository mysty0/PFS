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
	for (int i = 0; i < 4; i++)
		if(!write(pointer + i, (val >> (i * 8)))) return false;
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

int FileByteStream::read_int(FileBytePointer pointer){
	return ((int)read(pointer+3) << 24) | ((int)read(pointer+2) << 16) | ((int)read(pointer+1) << 8) | ((int)read(pointer));
}

int FileByteStream::read_string(FileBytePointer pointer, std::string &str){
	int size = read_int(pointer);
	if (size < 0) return -1;
	std::string res;
	for (int i = 0; i < size; ++i) {
		res.push_back(read(pointer + 4 + i));
	}
	str = res;
	return pointer+size+4;
}

FileSize FileByteStream::get_size(){
	return descriptor->get_size();
}

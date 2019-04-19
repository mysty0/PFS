#include "FileStream.h"


FileStream::FileStream(Storage *storage){
	chunk = storage->allocate(1);
	descriptor = new FileDescriptor(storage, chunk);
}

FileStream::~FileStream(){
	delete descriptor;
}

FileByteStream* FileStream::open(){
	return new FileByteStream(descriptor);
}

#pragma once
#include "FileDescriptor.h"
class FileDataStream {
protected:
	FileDescriptor* descriptor;
public:
	FileDataStream(FileDescriptor* descriptor) : descriptor(descriptor) {}
};
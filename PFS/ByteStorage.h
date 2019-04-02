#pragma once
#include "StorageTypedef.h"

class ByteStorage {
protected:
	StorageSize storage_size;

public:
	virtual StorageSize size() { return storage_size; }

	virtual ~ByteStorage() {}

	virtual bool write(StoragePointer pointer, char* bytes, StorageFileSize size) = 0;
	virtual void read(StoragePointer pointer, char* buffer, StorageFileSize size) = 0;
};
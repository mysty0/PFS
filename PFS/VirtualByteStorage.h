#pragma once
#include "ByteStorage.h"
#include "StorageTypedef.h"

class VirtualByteStorage :
	public ByteStorage
{
private:
	char *bytes;

public:
	VirtualByteStorage(StorageSize size);
	~VirtualByteStorage();

	// Inherited via ByteStorage
	virtual bool write(StoragePointer pointer, const char * bytes, StorageFileSize size) override;
	virtual void read(StoragePointer pointer, char* buffer, StorageFileSize size) override;

	virtual void wipe() override;
};


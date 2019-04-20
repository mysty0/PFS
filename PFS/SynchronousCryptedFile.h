#pragma once

#include <string>

#include "File.h"
#include "FileByteStream.h"


class SynchronousCryptedFile :
	public File{

public:
	SynchronousCryptedFile(Storage* storage, Path path);
	~SynchronousCryptedFile();

	void crypt(std::string password);
};


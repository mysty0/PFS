#pragma once

#include <string>

#include "File.h"
#include "FileByteStream.h"


class SymmetricCryptedFile :
	public File{

public:
	SymmetricCryptedFile(Storage* storage, Path path);
	~SymmetricCryptedFile();

	void crypt(std::string password);
};


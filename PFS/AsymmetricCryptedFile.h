#pragma once
#include <stdlib.h> 

#include "File.h"
#include "UserTable.h"

class AsymmetricCryptedFile :
	public File
{
public:
	AsymmetricCryptedFile(Storage* storage, Path path);
	~AsymmetricCryptedFile();

	void crypt(UserTable* users);
};


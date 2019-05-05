#pragma once
#include <stdlib.h> 

#include "SymmetricCryptedFile.h"
#include "UserTable.h"
#include "Hasher.h"
#include "AsymmetricCryptor.h"
#include "File.h"

class AsymmetricCryptedFile :
	public SymmetricCryptedFile
{
public:
	AsymmetricCryptedFile(Storage* storage, Path path);
	AsymmetricCryptedFile(File file);
	~AsymmetricCryptedFile();

	void crypt(UserTable* users);
};


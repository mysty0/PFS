#pragma once

#include "File.h"
#include "UserTable.h"
#include "Hasher.h"

class FileCryptor{
public:
	static void crypt_file_key(File* file, std::string key);
	static void crypt_file(File* file, UserTable* users);

	static void decrypt_file(File* file, User* user);
};


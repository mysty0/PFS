#include "AsymmetricCryptedFile.h"



AsymmetricCryptedFile::AsymmetricCryptedFile(Storage* storage, Path path) : File::File(storage, path)
{
}


AsymmetricCryptedFile::~AsymmetricCryptedFile()
{
}

long long crypt_key(std::string pub_key, long long n) {
	long long pkey = 0;
	for (char c : pub_key) pkey += (int)c;
	long long res = 1;
	for (int i = 0; i < pkey; ++i) res *= res;
	return res % n;
}

void write_key(std::vector<char>& out, long long key) {
	for (int i = 0; i < 8; ++i) out.push_back(key << (7 - i) * 8 >> (7 + i) * 8);
}	

void AsymmetricCryptedFile::crypt(UserTable* users){
	BigInt key = rand();
	long long n = rand();

	FileByteStream* stream = open_stream("keys");

	std::vector<char> data;
	write_key(data, n);

	int i = 0;
	for (User* user : users->get_users()) {
		int ukey = 0;
		
		//write_key(data, cryp_key(ukey, n));
		//stream->write(i, )
	}
	
}

#include "AsymmetricCryptedFile.h"



AsymmetricCryptedFile::AsymmetricCryptedFile(Storage* storage, Path path) : SymmetricCryptedFile::SymmetricCryptedFile(storage, path)
{
}

AsymmetricCryptedFile::AsymmetricCryptedFile(File file): SymmetricCryptedFile::SymmetricCryptedFile(file)
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
	FileByteStream* stream = open_stream("keys");

	BigInt key(Hasher::bigint_hash(rand(), 32));

	std::string data;
	//write_key(data, n);

	int i = 0;
	for (User* user : users->get_users()) {
		i = stream->write_string(i, AsymmetricCryptor::crypt_key(user->get_public_key(), user->get_private_key(), key).to_string());
	}
	
	delete stream;
	
	SymmetricCryptedFile::crypt(key.to_string());
}

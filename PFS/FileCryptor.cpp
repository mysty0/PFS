#include "FileCryptor.h"

long long crypt_key(std::string pub_key, long long n) {
	long long pkey = 0;
	for (char c : pub_key) pkey += (int)c;
	long long res = 1;
	for (int i = 0; i < pkey; ++i) res *= res;
	return res % n;
}

void write_key(std::vector<char> & out, long long key) {
	for (int i = 0; i < 8; ++i) out.push_back(key << (7 - i) * 8 >> (7 + i) * 8);
}

void FileCryptor::crypt_file_key(File* file, std::string key) {
	FileByteStream* fstream = (FileByteStream*)file->open(0);

	for (int i = 0; i < fstream->get_size(); ++i) {
		fstream->write(i, fstream->read(i) ^ key[i % key.length()]);
	}
	delete fstream;
}

void FileCryptor::crypt_file(File* file, UserTable* users) {
	FileByteStream* stream = file->open_stream("keys");

	BigInt key(Hasher::bigint_hash(rand(), 6));

	std::string data;
	//write_key(data, n);

	int i = 0;
	for (User* user : users->get_users()) {
		i = stream->write_string(i, user->get_name());
		i = stream->write_string(i, AsymmetricCryptor::crypt_key(key, user->get_public_key(), user->get_n()).to_string());
	}

	delete stream;

	crypt_file_key(file, key.to_string());
}

void FileCryptor::decrypt_file(File* file, User* user){
	int i = 0;
	FileByteStream* stream = file->open_stream("keys");
	while (i < stream->get_size()) {
		std::string user_name;
		if (stream->read_int(i) < 0) return;
		i = stream->read_string(i, user_name);
		if (stream->read_int(i) < 0) return;
		std::string pass;
		i = stream->read_string(i, pass);

		std::cout << user_name << " " << pass << std::endl;
		if (user->get_name() == user_name) {
			BigInt key(AsymmetricCryptor::crypt_key(BigInt(pass), user->get_private_key(), user->get_n()));
			crypt_file_key(file, key.to_string());
			delete stream;
			return;
		}
	}
	delete stream;
}

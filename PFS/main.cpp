#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "StorageChunk.h"
#include "Storage.h"
#include "StreamTable.h"
#include "Path.h"
#include "FileSystem.h"
#include "CommandManager.h"
#include "FileListCommand.h"
#include "MakeDirectoryCommand.h"
#include "CreateFileCommand.h"
#include "ReadFileCommand.h"
#include "CryptFileCommand.h"
#include "AddUserCommand.h"
#include "PrimeGenerator.h"
#include "AsymmetricCryptor.h"
#include "BigInt.h"
#include "Hasher.h"

using namespace std;


void prime_gen() {
	for (int i = 0; i < 100; ++i) {
		std::cout << PrimeGenerator::generate_prime(100000000000000, 10000000, 128) << std::endl;
		std::cout << "Primes cache: " << PrimeGenerator::prime_cache_size() << " non prime: " << PrimeGenerator::non_prime_cache_size() << std::endl;
	}
}

int main() {
	//Storage storage(1024, 64);
	//StorageChunk* chunk = storage.allocate(3000);
	//cout << chunk;
	//File* file = new File(&storage, Path());
	//delete file;
	//PrimeGenerator::is_prime(11);
	//cout << (BigInt(100) / BigInt(10) ) << endl;
	//return 0;
	//BigInt(222) % BigInt(4);

	//cout << (BigInt(995883480) % 2) << endl;

	srand(time(NULL));

	//BigInt pub, priv, n;
	//AsymmetricCryptor::generate_keys(pub, priv, n);

	//cout << pub.value() << " " << priv.value() << " " << n.value() << std::endl;

	//BigInt crypted = AsymmetricCryptor::crypt_key(123, pub, n);
	//cout << "Crypted: " << crypted << std::endl;
	//cout << "Encrypted: " << AsymmetricCryptor::crypt_key(crypted, priv, n) << std::endl;

	//cout << Hasher::bigint_hash(123, 20) << std::endl;

	//return 0;

	FileSystem fs = FileSystem();
	
	File *file = fs.create_directory(Path(), "test");
	CommandManager cm = CommandManager();
	cm.register_handler("ls", new FileListCommand(&fs));
	cm.register_handler("mkdir", new MakeDirectoryCommand(&fs));
	cm.register_handler("write", new CreateFileCommand(&fs));
	cm.register_handler("read", new ReadFileCommand(&fs));
	cm.register_handler("crypt", new CryptFileCommand(&fs));
	cm.register_handler("useradd", new AddUserCommand(&fs));
	
	while (true) {
		string command;
		getline(cin, command);
		if (command == "exit") break;
		cm.process_command(command, cout);
	}

	system("pause");
	return 0;
}
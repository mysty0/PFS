#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include "CppUnitTest.h"

#include "../PFS/FileSystem.h"
#include "../PFS/Hasher.cpp"
#include "../PFS/FileCryptor.cpp"
#include "../PFS/AsymmetricCryptor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(AsymmetricCryptorTests) {
	public:
		std::wstring string_to_wstring(const std::string & s)
		{
			std::wstring wsTmp(s.begin(), s.end());
			//ws = wsTmp;
			return wsTmp;
		}
		TEST_METHOD(Encrypt_Test) {
			BigInt pub, priv, n;
			AsymmetricCryptor::generate_keys(pub, priv, n);
			BigInt key(Hasher::bigint_hash(BigInt(123), 8));

			BigInt crypt(AsymmetricCryptor::crypt_key(key, pub, n));
			BigInt encr(AsymmetricCryptor::crypt_key(crypt, priv, n));
			Assert::AreEqual(key.to_string(), encr.to_string(), string_to_wstring(pub.to_string() + " " + priv.to_string() + " " + n.to_string()).c_str());
		}  

		TEST_METHOD(Encrypt_File_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_int(0, 123);

			UserTable* table = system.get_user_table();
			table->add_user(new User("user"));

			FileCryptor::crypt_file(file, table);

			User* user = table->get_user("user");
			FileCryptor::decrypt_file(file, user);

			int res = stream->read_int(0);
			Assert::AreEqual(std::string("123"), std::to_string(res));
		}
	};
}
#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include "CppUnitTest.h"

//#include "../PFS/BigInt.cpp"
#include "../PFS/AsymmetricCryptor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(AsymmetricCryptorTests) {
	public:
		TEST_METHOD(Encrypt_Test) {
			BigInt pub, priv, n;
			AsymmetricCryptor::generate_keys(pub, priv, n);
			BigInt key(1234);
			BigInt crypt(AsymmetricCryptor::crypt_key(key, pub, n));
			BigInt encr(AsymmetricCryptor::crypt_key(crypt, priv, n));
			Assert::AreEqual(std::to_string(1234), encr.to_string());
		}  
	};
}
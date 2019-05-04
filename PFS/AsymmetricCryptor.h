#pragma once
#include "BigInt.h"
#include "PrimeGenerator.h"
#include <iostream>


class AsymmetricCryptor{
public:

	static void generate_keys(BigInt& public_key, BigInt& private_key, BigInt& n);
	static BigInt crypt_key(const BigInt& key, const BigInt& n, const BigInt& ukey);
};


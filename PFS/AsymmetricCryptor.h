#pragma once
#include "BigInt.h"
#include "PrimeGenerator.h"


class AsymmetricCryptor{
public:

	static void generate_keys(BigInt& public_key, BigInt& private_key, BigInt& n);

};


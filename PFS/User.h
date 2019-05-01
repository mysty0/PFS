#pragma once

#include <string>

#include "BigInt.h"
#include "AsymmetricCryptor.h"

class User{
	std::string name;
	BigInt public_key;
	BigInt private_key;
	BigInt n;

public:
	User(std::string name, BigInt public_key, BigInt private_key, BigInt n);
	User(std::string name);
	~User();

	std::string get_name() const;
	BigInt get_public_key() const;
	BigInt get_private_key() const;
	BigInt get_n() const;
};


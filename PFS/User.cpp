#include "User.h"

User::User(std::string name, BigInt public_key, BigInt private_key, BigInt n) : name(name), public_key(public_key), private_key(private_key), n(n)
{
}

User::User(std::string name): name(name){
	AsymmetricCryptor::generate_keys(public_key, private_key, n);
}

User::~User()
{
}

std::string User::get_name() const{
	return name;
}

BigInt User::get_public_key() const {
	return public_key;
}
BigInt User::get_private_key() const {
	return private_key;
}
BigInt User::get_n() const {
	return n;
}

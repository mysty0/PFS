#include "User.h"


User::User(std::string name, std::string public_password, std::string private_password): name(name), public_password(public_password), private_password(private_password)
{
}

User::~User()
{
}

std::string User::get_name() const{
	return name;
}

std::string User::get_public_password() const{
	return public_password;
}

long long User::crypt_key(long long key, long long n){
	long long pkey = 0;
	for (char c : private_password) pkey += (int)c;
	long long res = 1;
	for (int i = 0; i < pkey; ++i) res *= key;
	return res % n;
}

#pragma once

#include <string>

class User{
	std::string name;
	std::string public_password;
	std::string private_password;

public:
	User(std::string name, std::string public_password, std::string private_password);
	~User();

	std::string get_name() const;
	std::string get_public_password() const;

	long long crypt_key(long long key, long long n);
};


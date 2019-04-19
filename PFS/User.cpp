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

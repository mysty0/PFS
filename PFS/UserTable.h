#pragma once
#include "User.h"
#include <vector>
#include <string>

class UserTable{
	std::vector<User*> users;

public:
	UserTable();
	~UserTable();

	void add_user(User* user);
	void delete_user(std::string name);
	User* get_user(std::string name);

	std::vector<User*> get_users();
};


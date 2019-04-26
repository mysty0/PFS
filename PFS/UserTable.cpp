#include "UserTable.h"



UserTable::UserTable()
{
}


UserTable::~UserTable(){
	for (const User* user : users) delete user;
}

void UserTable::add_user(User* user){
	users.push_back(user);
}

void UserTable::delete_user(std::string name){
	for (std::vector<User*>::iterator iter = users.begin(); iter != users.end(); iter++) 
		if ((*iter)->get_name() == name) {
			delete (*iter);
			users.erase(iter);
		}
}

User* UserTable::get_user(std::string name){
	for (std::vector<User*>::iterator iter = users.begin(); iter != users.end(); iter++)
		if ((*iter)->get_name() == name) return (*iter);
}

std::vector<User*> UserTable::get_users(){
	return std::vector<User*>(users);
}

#pragma once
#include <ctime>
#include <string>

class File{
	std::string name;
	
	std::time_t created_date;
	std::time_t modified_date;



public:
	File();
	~File();


};


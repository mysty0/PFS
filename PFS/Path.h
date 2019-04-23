#pragma once
#include <vector>
#include <string>

#include "Utils.h"

class Path{
	std::vector<std::string> directories;
public:
	Path();
	Path(std::vector<std::string> directories);
	Path(std::string string);
	~Path();

	std::vector<std::string> get_directories() const;
	std::string to_string() const;

	Path parent() const;

	Path operator+(std::string dir);

};


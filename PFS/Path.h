#pragma once
#include <vector>
#include <string>

class Path{
	std::vector<std::string> directories;
public:
	Path();
	Path(std::vector<std::string> directories);
	~Path();

	std::vector<std::string> get_directories() const;
	std::string to_string() const;

	Path operator+(std::string dir);
};


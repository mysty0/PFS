#pragma once
#include <vector>
#include <string>

#include "Directory.h"
class Path
{
	std::vector<Directory> directories;
public:
	Path(std::vector<Directory> directories);
	~Path();

	std::vector<Directory> get_directories() const;
	std::string to_string() const;
};


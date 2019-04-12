#include "Path.h"

Path::Path(std::vector<Directory> directories): directories(directories){
}

Path::~Path()
{
}

std::vector<Directory> Path::get_directories() const{
	return directories;
}

std::string Path::to_string() const{
	std::string str;
	for (const Directory &dir : directories) str.append("/" + str);
	return str;
}

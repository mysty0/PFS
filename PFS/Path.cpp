#include "Path.h"

Path::Path() : directories(std::vector<std::string>()) {
}

Path::Path(std::vector<std::string> directories): directories(directories){
}

Path::Path(std::string string){
	split_string(string, directories, '/');
}

Path::~Path()
{
}

std::vector<std::string> Path::get_directories() const{
	return directories;
}

std::string Path::to_string() const{
	std::string str;
	for (const std::string &dir : directories) str.append("/" + dir);
	return str;
}

Path Path::parent() const{
	if (directories.size() == 1) return Path(*this);
	return Path(std::vector<std::string>(&directories[0], &directories[directories.size() - 2]));
}

Path Path::operator+(std::string dir){
	std::vector<std::string> new_path(directories);
	new_path.push_back(dir);
	return Path(new_path);
}

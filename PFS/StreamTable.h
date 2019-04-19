#pragma once
#include <map>
#include <string>

#include "FileStream.h"
class StreamTable{
	std::map<std::string, FileStream*> streams;
	Storage* storage;

public:
	StreamTable(Storage *storage);
	~StreamTable();

	FileStream* get_stream(std::string name);
	FileStream* create_stream(std::string name);
	void delete_stream(std::string name);
};


#pragma once

#include <exception>
#include <string>

class StorageException : public std::exception {
	std::string reason;
public:
	StorageException(std::string reason): reason(reason){}

	std::string get_reason() { return reason; }
};
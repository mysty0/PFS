#include "File.h"



File::File(Storage * storage){
	this->descripor = FileDescriptor(storage);
}


File::~File()
{
}

bool File::create(){
	return descripor.create(default_file_size);
}

FileDataStream File::open(char flags){
	return FileByteStream(&descripor);
}

std::string File::get_name(){
	return name;
}

void File::set_name(std::string name){
	this->name = name;
}



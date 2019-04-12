#include "FileSystem.h"



FileSystem::FileSystem(): storage(Storage(1024, 64)){
	Directory *dir = new Directory(&storage);
	dir->create();
	root_dir = dir;
}


FileSystem::~FileSystem()
{
}

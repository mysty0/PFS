#include "FilePermissions.h"


FilePermissions::FilePermissions(bool can_read, bool can_write): cread(can_read), cwrite(can_write){
}

FilePermissions::~FilePermissions()
{
}

bool FilePermissions::can_read(){
	return cread;
}

bool FilePermissions::can_write(){
	return cwrite;
}

#include "DirectoryPermissions.h"



DirectoryPermissions::DirectoryPermissions(bool can_read, bool can_write, bool can_pass): FilePermissions(can_pass, can_write), cpass(can_pass){
}


DirectoryPermissions::~DirectoryPermissions()
{
}

bool DirectoryPermissions::can_pass(){
	return cpass;
}

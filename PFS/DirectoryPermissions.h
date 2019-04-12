#pragma once
#include "FilePermissions.h"
class DirectoryPermissions :
	public FilePermissions
{
	bool cpass;
public:
	DirectoryPermissions(bool can_read = false, bool can_write = false, bool can_pass = false);
	~DirectoryPermissions();

	bool can_pass();
};


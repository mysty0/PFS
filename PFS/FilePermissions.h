#pragma once
class FilePermissions{
	bool cread;
	bool cwrite;
public:
	FilePermissions(bool can_read = false, bool can_write = false);
	~FilePermissions();

	bool can_read();
	bool can_write();
};


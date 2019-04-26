#include <iostream>
#include <string>

#include "StorageChunk.h"
#include "Storage.h"
#include "StreamTable.h"
#include "Path.h"
#include "FileSystem.h"
#include "CommandManager.h"
#include "FileListCommand.h"
#include "MakeDirectoryCommand.h"
#include "CreateFileCommand.h"
#include "ReadFileCommand.h"

using namespace std;

int main() {
	//Storage storage(1024, 64);
	//StorageChunk* chunk = storage.allocate(3000);
	//cout << chunk;
	//File* file = new File(&storage, Path());
	//delete file;
	FileSystem fs = FileSystem();
	
	File *file = fs.create_directory(Path(), "test");
	CommandManager cm = CommandManager();
	cm.register_handler("ls", new FileListCommand(&fs));
	cm.register_handler("mkdir", new MakeDirectoryCommand(&fs));
	cm.register_handler("write", new CreateFileCommand(&fs));
	cm.register_handler("read", new ReadFileCommand(&fs));
	
	while (true) {
		string command;
		getline(cin, command);
		if (command == "exit") break;
		cm.process_command(command, cout);
	}

	system("pause");
	return 0;
}
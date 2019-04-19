#include <iostream>
#include "StorageChunk.h"
#include "Storage.h"
#include "StreamTable.h"
#include "File.h"
#include "Path.h"

using namespace std;

int main() {
	Storage storage(1024, 64);
	//StorageChunk* chunk = storage.allocate(3000);
	//cout << chunk;
	File* file = new File(&storage, Path());
	delete file;

	system("pause");
	return 0;
}
#include <iostream>
#include "StorageChunk.h"
#include "Storage.h"

using namespace std;

int main() {
	Storage storage(1024, 64);
	StorageChunk* chunk = storage.allocate(3000);
	cout << chunk;

	system("pause");
	return 0;
}
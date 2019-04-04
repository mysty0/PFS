#include "stdafx.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../PFS/Storage.h"
#include "../PFS/Storage.cpp"
#include "../PFS/StorageChunk.h"
#include "../PFS/StorageChunk.cpp"
#include "../PFS/FileDescriptor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(FileDescriptorTest) {
	public:
		TEST_METHOD(Create_Test) {
			Storage * stor = new Storage(256, 64);
			FileDescriptor fd(stor);
			bool res = fd.create(10);
			Assert::IsTrue(res);
			delete stor;
		}

		TEST_METHOD(Write_Read_Test) {
			Storage * stor = new Storage(256, 64);
			stor->wipe();
			FileDescriptor fd(stor, 50);
			char * bytes = "Hi world";
			bool res = fd.write(0, bytes, 8);
			Assert::IsTrue(res);
			char * read_res = fd.read(0, 8);
			Assert::IsTrue(!std::memcmp(bytes, read_res, 8));
			delete [] read_res;
			delete stor;
		}
	};
}
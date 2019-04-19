#include "stdafx.h"
#include <iostream>
#include <string>
#include "CppUnitTest.h"

#include "../PFS/FileSystem.cpp"
#include "../PFS/Path.cpp"
#include "../PFS/File.cpp"
#include "../PFS/FilePermissions.cpp"
#include "../PFS/FileByteStream.cpp"
#include "../PFS/Directory.cpp"
#include "../PFS/DirectoryStream.cpp"
#include "../PFS/StreamTable.cpp"
#include "../PFS/FileStream.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(FileSystemTest) {
	public:
		TEST_METHOD(Create_File_Test) {
			FileSystem system = FileSystem();
			File *file = system.create_file(Path(), "test");
			bool res = system.get_directory(Path(), false)->is_file_exists(file);
			Assert::IsTrue(file && res);
		}
		TEST_METHOD(Delete_File_Test) {
			FileSystem system = FileSystem();
			File *file = system.create_file(Path(), "test");
			system.delete_file(file);
			bool res = system.get_directory(Path(), false)->is_file_exists(file);
			Assert::IsTrue(file && !res);
		}
		TEST_METHOD(Crete_Directory_Test) {
			FileSystem system = FileSystem();
			Directory *dir = system.create_directory(Path(), "test");
			File *file = system.create_file(dir->get_path(), "tst");
			bool res = dir->is_file_exists(file);
			Assert::IsTrue(file && res && dir);
		}
		TEST_METHOD(Move_File_Test) {
			FileSystem system = FileSystem();
			Directory *dir = system.create_directory(Path(), "test");
			Directory *dir1 = system.create_directory(Path(), "test1");
			File *file = system.create_file(dir->get_path(), "tst");
			bool res = dir->is_file_exists(file);
			system.move(file, dir1->get_path());
			res &= dir1->is_file_exists(file);
			Assert::IsTrue(file && res && dir);
		}
		TEST_METHOD(Write_To_File_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			char bytes[] = "test_1";
			stream->write(0, bytes, 6);
			char* read_bytes = stream->read(0, 6);
			Assert::IsTrue(!strncmp(bytes, read_bytes, 6));
			delete read_bytes;
		}
		TEST_METHOD(Write_To_File_Stream_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = file->open_stream("test");
			char bytes[] = "test_1";
			bool res = stream->write(0, bytes, 6);
			char* read_bytes = stream->read(0, 6);
			Assert::IsTrue(!strncmp(bytes, read_bytes, 6) && res);
			delete read_bytes;
		}
	};

}
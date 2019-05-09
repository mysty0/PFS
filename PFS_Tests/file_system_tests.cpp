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
#include "../PFS/User.cpp"
#include "../PFS/UserTable.cpp"
#include "../PFS/SymmetricCryptedFile.cpp"

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

		TEST_METHOD(Byte_Stream_Int_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_int(0, 123);
			int res = stream->read_int(0);
			Assert::AreEqual(std::string("123"), std::to_string(res));
			delete stream;
		}

		TEST_METHOD(Byte_Stream_Int4_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_int(0, 4);
			int res = stream->read_int(0);
			Assert::AreEqual(std::string("4"), std::to_string(res));
			delete stream;
		}

		TEST_METHOD(Byte_Stream_String_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_string(0, "1234");
			std::string res;
			stream->read_string(0, res);
			Assert::AreEqual(std::string("1234"), res);
			delete stream;
		}
		TEST_METHOD(Byte_Stream_String_user_Test) {
			FileSystem system = FileSystem();
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_string(0, "user");
			std::string res;
			stream->read_string(0, res);
			Assert::AreEqual(std::string("user"), res);
			delete stream;
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
			delete stream;
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

		TEST_METHOD(User_Table_Test) {
			FileSystem system = FileSystem();
			UserTable* table = system.get_user_table();
			table->add_user(new User("test", 3, 3, 3));
			table->add_user(new User("test1", 3, 3, 3));
			User* user = table->get_user("test");
			Assert::IsTrue(user->get_name() == "test");
		}

		TEST_METHOD(User_Table_Test1) {
			FileSystem system = FileSystem();
			system.wipe();
			
			File* file = system.create_file(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			stream->write_int(0, 123);

			UserTable* table = system.get_user_table();
			table->add_user(new User("user"));

			FileByteStream* streamKeys = file->open_stream("keys");


			std::string data;

			int i = 0;
			for (User* user : table->get_users()) {
				i = streamKeys->write_string(i, user->get_name());
				i = streamKeys->write_string(i, "test string");
			}

			delete streamKeys;
			i = 0;
			User* user = table->get_user("user");
			FileByteStream* streamRead = file->open_stream("keys");
			std::string user_name;
			i = streamRead->read_string(i, user_name);

			//if (stream->read_int(i) < 0) return;
			Assert::AreEqual(i, 8);
			Assert::AreEqual(std::string("user"), user_name);

			int res = stream->read_int(0);
			Assert::AreEqual(std::string("123"), std::to_string(res));
		}


		TEST_METHOD(Crypt_File_Test) {
			FileSystem system = FileSystem();
			SymmetricCryptedFile* file = system.create_file<SymmetricCryptedFile>(Path(), "test");
			FileByteStream* stream = (FileByteStream*)file->open(0);
			char bytes[] = "test_2";
			stream->write(0, bytes, 6);
			file->crypt("123");
			char* read_bytes = stream->read(0, 6);
			Assert::IsTrue(strncmp(bytes, read_bytes, 6));
			delete read_bytes;
			file->crypt("123");
			read_bytes = stream->read(0, 6);
			Assert::IsTrue(!strncmp(bytes, read_bytes, 6));

			delete stream;
		}
	};

}
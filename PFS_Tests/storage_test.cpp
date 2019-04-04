#include "stdafx.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../PFS/Storage.h"

#include "../PFS/StorageChunk.h"

#include "../PFS/MapChunkStorage.cpp"
#include "../PFS/VirtualByteStorage.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests{		
	TEST_CLASS(StorageTest){
	public:
		TEST_METHOD(Allocation_Test){
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(64);
			Assert::IsNotNull(chunk);
		}

		TEST_METHOD(Allocation_Max_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(960);
			Assert::IsNotNull(chunk);
		}

		TEST_METHOD(Allocation_Min_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(1);
			Assert::IsNotNull(chunk);
		}

		TEST_METHOD(Allocation_Overflow_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(3000);
			Assert::IsTrue(chunk == nullptr);
		}
		TEST_METHOD(Allocation_Multiple_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(300);
			StorageChunk* chunk1 = storage.allocate(300);
			StorageChunk* chunk2 = storage.allocate(300);
			Assert::IsTrue(chunk && chunk1 && chunk2);
		}
		TEST_METHOD(Allocation_Multiple_Overflow_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(300);
			StorageChunk* chunk1 = storage.allocate(500);
			StorageChunk* chunk2 = storage.allocate(300);
			Assert::IsTrue(chunk && chunk1 && !chunk2);
		}

		TEST_METHOD(Deallocation_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(960);
			storage.deallocate(chunk);
			StorageChunk* chunk1 = storage.allocate(960);

			Assert::IsNotNull(chunk1);
		}

		TEST_METHOD(Deallocation_Multiple_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(500);
			StorageChunk* chunk1 = storage.allocate(400);
			storage.deallocate(chunk);
			StorageChunk* chunk2 = storage.allocate(400);

			Assert::IsTrue(chunk && chunk1 && chunk2);
		}
		TEST_METHOD(Deallocation_Multiple_Overflow_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(500);
			StorageChunk* chunk1 = storage.allocate(400);
			storage.deallocate(chunk);
			StorageChunk* chunk2 = storage.allocate(600);

			Assert::IsTrue(chunk && chunk1 && !chunk2);
		}
		TEST_METHOD(Resize_Increase_Test) {
			MapChunkStorage * chunks = new MapChunkStorage();
			Storage storage(1024, 64, chunks);
			StorageChunk* chunk = storage.allocate(500);
			bool res = storage.resize(chunk, 700);
			Assert::IsTrue(chunks->size() == 700/64+1);
			StorageChunk * chunk1 = storage.allocate(400);

			Assert::IsTrue(res && !chunk1);
		}
		TEST_METHOD(Resize_Decrease_Test) {
			MapChunkStorage * chunks = new MapChunkStorage();
			Storage storage(1024, 64, chunks);
			StorageChunk* chunk = storage.allocate(800);
			bool res = storage.resize(chunk, 500);
			Assert::IsTrue(chunks->size() == 500 / 64 + 1);
			StorageChunk * chunk1 = storage.allocate(400);

			Assert::IsTrue(res && chunk1);
		}
		TEST_METHOD(Resize_Increase_Overflow_Test) {
			MapChunkStorage * chunks = new MapChunkStorage();
			Storage storage(1024, 64, chunks);
			StorageChunk* chunk = storage.allocate(500);
			bool res = storage.resize(chunk, 2000);
			Assert::IsTrue(chunks->size() == 500 / 64 + 1);
			StorageChunk * chunk1 = storage.allocate(400);

			Assert::IsTrue(!res && chunk1);
		}

		TEST_METHOD(Write_Test) {
			VirtualByteStorage *byte_storage = new VirtualByteStorage(1024);
			byte_storage->wipe();
			Storage storage(1024, 64, byte_storage);
			StorageChunk * chunk = storage.allocate(100);
			char *bytes = "Hello";
			bool res = storage.write(chunk, 0, bytes, 5);
			Assert::IsTrue(res);
			char *buf = new char[5];
			byte_storage->read(chunk->pointer * 64, buf, 5);
			Assert::IsTrue(!std::memcmp(bytes, buf, 5));
			delete[] buf;
		}
		TEST_METHOD(Write_Overflow_Test) {
			VirtualByteStorage *byte_storage = new VirtualByteStorage(1024);
			byte_storage->wipe();
			Storage storage(20, 10, byte_storage);
			StorageChunk * chunk = storage.allocate(10);
			char *bytes = "12345678910";
			bool res = storage.write(chunk, 0, bytes, 11);
			Assert::IsFalse(res);
			char *buf = new char[10];
			byte_storage->read(chunk->pointer * 10, buf, 10);
			char *zeros = new char[10];
			std::memset(zeros, 0, 10);
			Assert::IsTrue(!std::memcmp(bytes, buf, 10));
			delete[] buf;
			delete[] zeros;
		}

		TEST_METHOD(Read_Test) {
			VirtualByteStorage *byte_storage = new VirtualByteStorage(1024);
			byte_storage->wipe();
			Storage storage(1024, 64, byte_storage);
			StorageChunk * chunk = storage.allocate(100);
			char *bytes = "Hello";
			bool res = storage.write(chunk, 0, bytes, 5);
			Assert::IsTrue(res);
			char *buf = new char[5];
			storage.read(chunk, 0, buf, 5);
			Assert::IsTrue(!std::memcmp(bytes, buf, 5));
			delete[] buf;
		}
		TEST_METHOD(Read_Multiple_Chunks_Test) {
			VirtualByteStorage *byte_storage = new VirtualByteStorage(1024);
			byte_storage->wipe();
			Storage storage(100, 4, byte_storage);
			StorageChunk * chunk = storage.allocate(80);
			char *bytes = "Hello000";
			bool res = storage.write(chunk, 0, bytes, 8);
			Assert::IsTrue(res);
			char *buf = new char[8];
			storage.read(chunk, 0, buf, 8);
			Assert::IsTrue(!std::memcmp(bytes, buf, 8));
			delete[] buf;
		}
		TEST_METHOD(Read_Multiple_Chunks_Different_Place_Test) {
			VirtualByteStorage *byte_storage = new VirtualByteStorage(1024);
			byte_storage->wipe();
			Storage storage(100, 4, byte_storage);
			StorageChunk * chunk = storage.allocate(80);
			char *bytes = "Hello000";
			bool res = storage.write(chunk, 33, bytes, 8);
			Assert::IsTrue(res);
			char *buf = new char[8];
			storage.read(chunk, 33, buf, 8);
			Assert::IsTrue(!std::memcmp(bytes, buf, 8));
			delete[] buf;
		}
	};
}
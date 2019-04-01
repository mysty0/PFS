#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PFS/Storage.h"
#include "../PFS/Storage.cpp"
#include "../PFS/StorageChunk.h"
#include "../PFS/StorageChunk.cpp"
#include "../PFS/MapChunkStorage.cpp"

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
		TEST_METHOD(Resize_increase_Test) {
			Storage storage(1024, 64);
			StorageChunk* chunk = storage.allocate(500);
			bool res = storage.resize(chunk, 700);
			StorageChunk * chunk1 = storage.allocate(400);

			Assert::IsTrue(res && !chunk1);
		}
	};
}
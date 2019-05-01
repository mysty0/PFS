#include "stdafx.h"
#include <iostream>
#include <string>
#include "CppUnitTest.h"

#include "../PFS/PrimeGenerator.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(Prime_Generator_Test) {
	public:
		TEST_METHOD(Prime_Test) {
			unsigned long long prime = 0;
			while(prime < 10) 
				prime = PrimeGenerator::generate_prime(100);
			for (int i = 2; i < prime; ++i) if (i != prime && prime % i == 0) Assert::IsTrue(false);
			Assert::IsTrue(true);
		}
	};
}
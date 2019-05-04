#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
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

		TEST_METHOD(Mod_Pow_Test) {
			unsigned long long a = 12;
			unsigned long long b = 5;
			unsigned long long c = 21;
			
			Assert::AreEqual(std::to_string((long long)std::pow(12, 5) % 21), std::to_string(PrimeGenerator::pow_mod(a,b,c)));
		}
	};
}
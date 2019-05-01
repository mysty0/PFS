#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include "CppUnitTest.h"

#include "../PFS/BigInt.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PFS_Tests {

	TEST_CLASS(BigIntTest) {
	public:
		TEST_METHOD(Multiply_Test) {
			BigInt a(312143423);
			BigInt b(54099734);

			BigInt r = a * b;

			Assert::AreEqual(std::to_string((long long)312143423 * 54099734), std::to_string(r.value()));
		}

		TEST_METHOD(Multiply_Ordinary_Test) {
			BigInt a(312143423);
			long long b(54099734);

			BigInt r = a * b;

			Assert::AreEqual(std::to_string((long long)312143423 * 54099734), std::to_string(r.value()));
		}

		TEST_METHOD(Multiply_Diff_Size_Test) {
			BigInt a(31214);
			BigInt b(54099734);

			BigInt r = a * b;

			Assert::AreEqual(std::to_string((long long)31214 * 54099734), std::to_string(r.value()));
		}

		TEST_METHOD(Multiply_Same_Size_Test) {
			BigInt a(31214333);
			BigInt b(54099734);

			BigInt r = a * b;

			Assert::AreEqual(std::to_string((long long)31214333 * 54099734), std::to_string(r.value()));
		}

		TEST_METHOD(Plus_Test) {
			BigInt a(67567243242);
			BigInt b(329343328);

			BigInt r = a + b;

			Assert::AreEqual(std::to_string((long long)67567243242 + 329343328), std::to_string(r.value()));
		}

		TEST_METHOD(Plus_Ordinary_Test) {
			BigInt a(67567243242);
			long long b(329343328);

			BigInt r = a + b;

			Assert::AreEqual(std::to_string((long long)67567243242 + 329343328), std::to_string(r.value()));
		}

		TEST_METHOD(Plus_Diff_Size_Test) {
			BigInt a(987349);
			BigInt b(54099734324342);

			BigInt r = a + b;

			Assert::AreEqual(std::to_string((long long)987349 + 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Plus_Same_Size_Test) {
			BigInt a(98734934334341);
			BigInt b(54099734324342);

			BigInt r = a + b;

			Assert::AreEqual(std::to_string((long long)98734934334341 + 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Is_Greater_Test) {
			BigInt a(345242342);
			BigInt b(93437848923847);

			Assert::IsTrue((a > b) == (345242342 > 93437848923847));
		}

		TEST_METHOD(Is_Greater_Ordinary_Test) {
			BigInt a(345242342);
			long long b(93437848923847);

			Assert::IsTrue((a > b) == (345242342 > 93437848923847));
		}

		TEST_METHOD(Is_Greater1_Test) {
			BigInt a(999374737);
			BigInt b(2132334);

			Assert::IsTrue((a > b) == (999374737 > 2132334));
		}
		TEST_METHOD(Is_Greater_Same_Test) {
			BigInt a(999374737);
			BigInt b(213233433);

			Assert::IsTrue((a > b) == (999374737 > 213233433));
		}

		TEST_METHOD(Minus_Test) {
			BigInt a(100);
			BigInt b(10);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)100 - 10), std::to_string(r.value()));
		}

		TEST_METHOD(Minus_Ordinary_Test) {
			BigInt a(100);
			long long b(10);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)100 - 10), std::to_string(r.value()));
		}

		TEST_METHOD(Minus1_Test) {
			BigInt a(675672432000);
			BigInt b(329343328);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)675672432000 - 329343328), std::to_string(r.value()));
		}

		TEST_METHOD(Minus_Diff_Size_Test) {
			BigInt a(987349);
			BigInt b(54099734324342);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)987349 - 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Minus_Same_Size_Test) {
			BigInt a(98734934334341);
			BigInt b(54099734324342);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)98734934334341 - 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Test) {
			BigInt a(100);
			BigInt b(10);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)100 / 10), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Diff_Size_Test) {
			BigInt a(987349);
			BigInt b(54099734324342);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)987349 / 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Same_Size_Test) {
			BigInt a(98734934334341);
			BigInt b(54099734324342);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)98734934334341 / 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Increment_test) {
			BigInt a(0);

			for (int i = 0; i < 12345; ++i) ++a;

			Assert::AreEqual(std::to_string((long long)12345), std::to_string(a.value()));
		}

		TEST_METHOD(Pow_test) {
			BigInt a(666);
			BigInt b(66);

			BigInt r = a ^ b;

			Assert::AreEqual(std::to_string((long long)std::pow((long long)666, 66)), std::to_string(r.value()));
		}
	};
}
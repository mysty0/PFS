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

		TEST_METHOD(Pow_Mod_Test) {
			BigInt a(12);
			BigInt b(5);
			BigInt n(21);

			BigInt r = a.pow_mod(b, n);

			Assert::AreEqual(std::to_string((long long)std::pow(12, 5) % 21), std::to_string(r.value()));
		}

		TEST_METHOD(Pow2_Mod_Test) {
			BigInt a(3212);
			BigInt b(4);
			BigInt n(3345);

			BigInt r = a.pow_mod(b, n);

			Assert::AreEqual(std::to_string((long long)std::pow(3212, 4) % 3345), std::to_string(r.value()));
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
			BigInt a(101);
			BigInt b(9);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)101 - 9), std::to_string(r.value()));
		}

		TEST_METHOD(Minus5_Test) {
			BigInt a(25);
			BigInt b(5);

			a -= b;

			Assert::AreEqual(std::to_string((long long)25 - 5), std::to_string(a.value()));
		}
		TEST_METHOD(Minus_Zero_Test) {
			BigInt a(10);
			BigInt b(10);

			BigInt r = a - b;

			Assert::AreEqual(std::to_string((long long)0), std::to_string(r.value()));
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

			a -= b;

			Assert::AreEqual(std::to_string((long long)98734934334341 - 54099734324342), std::to_string(a.value()));
		}

		TEST_METHOD(Divide_Test) {
			BigInt a(100);
			BigInt b(10);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)100 / 10), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Big_Test) {
			BigInt a(9023749023);
			BigInt b(23456);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)9023749023 / 23456), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Diff_Size_Test) {
			BigInt a(987349);
			BigInt b(54099734324342);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)987349 / 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(Divide5_Size_Test) {
			BigInt a(25);
			BigInt b(5);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)25 / 5), std::to_string(r.value()));
		}

		TEST_METHOD(Divide52_Size_Test) {
			BigInt a(5);
			BigInt b(2);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)5 / 2), std::to_string(r.value()));
		}

		TEST_METHOD(Divide_Same_Size_Test) {
			BigInt a(98734934334341);
			BigInt b(54099734324342);

			BigInt r = a / b;

			Assert::AreEqual(std::to_string((long long)98734934334341 / 54099734324342), std::to_string(r.value()));
		}

		TEST_METHOD(More_Or_Equal_Test) {
			BigInt a(9873492323233111);
			BigInt b(54099734324342);

			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(More_Or_Equal_Same_Size_Test) {
			BigInt a(9873492323233111);
			BigInt b(9999999999999999);

			Assert::IsTrue(!(a >= b));
		}

		TEST_METHOD(More_or_Equal_False_Test) {
			BigInt a(902348702);
			BigInt b(12323433330);

			Assert::IsTrue(!(a >= b));
		}

		TEST_METHOD(Mod_Test) {
			BigInt a(222);
			BigInt b(4);

			BigInt r;
			r = a % b;

			Assert::AreEqual(std::to_string((long long)222 % 4), std::to_string(r.value()));
		}

		TEST_METHOD(Mod2_Test) {
			BigInt a(12);
			BigInt b(3);

			BigInt r;
			r = a % b;

			Assert::AreEqual(std::to_string((long long)12 % 3), std::to_string(r.value()));
		}

		TEST_METHOD(Mod_Big_Test) {
			BigInt a(92374900238);
			BigInt b(23452);

			BigInt r;
			r = a % b;

			Assert::AreEqual(std::to_string((long long)92374900238 % 23452), std::to_string(r.value()));
		}

		TEST_METHOD(Mod_Zero_Test) {
			BigInt a(22);
			BigInt b(22);

			BigInt r;
			r = a % b;
			Assert::IsTrue(r == 0);
			Assert::AreEqual(std::to_string((long long)22 % 22), std::to_string(r.value()));
		}

		TEST_METHOD(Zero_Compare_Test) {
			BigInt a(0);
			BigInt b(0);
			
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(Is_Even_Test) {
			BigInt a(100);

			Assert::IsTrue(a.is_even());
		}

		TEST_METHOD(Is_Even_False_Test) {
			BigInt a(201);

			Assert::IsTrue(!a.is_even());
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

		TEST_METHOD(Pow2_test) {
			BigInt a(12);
			BigInt b(5);

			BigInt r = a ^ b;

			Assert::AreEqual(std::to_string((long long)std::pow((long long)12, 5)), std::to_string(r.value()));
		}
	};
}
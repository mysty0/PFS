#pragma once

#include "BigInt.h"
#include <stdlib.h>
#include <set>

class PrimeGenerator
{
	
public:

	static unsigned long long generate_prime(unsigned long long max, unsigned long long min = 2, long test_number = 128);
	static bool is_prime(unsigned long long number, long test_number = 128);

	static unsigned long long random();
	static int prime_cache_size();
	static int non_prime_cache_size();
	static void wipe_cache();

};


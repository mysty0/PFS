#include "PrimeGenerator.h"

static std::set<unsigned long long> prime_cache;
static std::set<unsigned long long> non_prime_cache;

unsigned long long PrimeGenerator::pow_mod(unsigned long long a, unsigned long long x, unsigned long long n){
	unsigned long long r = 1;
	while (x) {
		if ((x & 1) == 1)
			r = a * r % n;
		x >>= 1;
		a = a * a % n;
	}

	return r;
}

unsigned long long PrimeGenerator::generate_prime(unsigned long long max, unsigned long long min, long test_number){
	unsigned long long p = 4;

	while (!is_prime(p, test_number)) {
		p = min + random() % max;
		p |= 1;
	}
	return p;
}

bool PrimeGenerator::is_prime(unsigned long long number, long test_number){
	if (prime_cache.find(number) != prime_cache.end()) return true;
	if (non_prime_cache.find(number) != non_prime_cache.end()) return false;
	if (number == 2 || number == 3) return true;
	if (number <= 1 || (number & 1) == 0) return false;

	unsigned long long s = 0;
	unsigned long long r = number-1;
	while ((r & 1) == 0) {
		++s;
		r /= 2;
	}
	for (int i = 0; i < test_number; ++i) {
		unsigned long long a = 2 + random() % (number - 2 + 1);
		unsigned long long x = pow_mod(a, r, number);
		if (x != 1 && x != number - 1) {
			unsigned long long j = 1;
			while (j < s && x != number - 1) {
				x = pow_mod(x, 2, number);
				if (x == 1) {
					non_prime_cache.insert(number);
					return false;
				}
				j += 1;
			}
			if (x != number - 1) {
				non_prime_cache.insert(number);
				return false;
			}
		}
	}
	prime_cache.insert(number);
	return true;
}

unsigned long long PrimeGenerator::random(){
	unsigned long long r = 0;
	for (int i = 0; i < sizeof(unsigned long long) / sizeof(int); i++)
	{
		r = r << (sizeof(int) * 8);
		r |= rand();
	}
	return r;
}

int PrimeGenerator::prime_cache_size(){
	return prime_cache.size();
}

int PrimeGenerator::non_prime_cache_size(){
	return non_prime_cache.size();
}

void PrimeGenerator::wipe_cache(){
	prime_cache.clear();
	non_prime_cache.clear();
}

#pragma once
#include <string>
#include <vector>

#include "BigInt.h"

class Hasher{

public:
	
	static std::string hash(std::string str, unsigned int size, unsigned int prime_hash_size = 1000);
	static BigInt bigint_hash(BigInt str, unsigned int size, unsigned int prime_hash_size = 1000);
};


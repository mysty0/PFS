#include "AsymmetricCryptor.h"



BigInt gcd(BigInt a, BigInt b){
	BigInt temp;
	while (true){
		temp = a % b;
		if (temp == 0)
			return b;
		a = b;
		b = temp;
	}
}

void AsymmetricCryptor::generate_keys(BigInt& public_key, BigInt& private_key, BigInt& n){
	BigInt p(PrimeGenerator::generate_prime(100));
	BigInt q(PrimeGenerator::generate_prime(100));

	n = p * q;

	public_key = 2;
	BigInt phi = (p - 1) * (q - 1);
	while (public_key < phi){
		if (gcd(public_key, phi) == 1)
			break;
		else
			++public_key;
	}
	BigInt k(39273);
	private_key = ((k * phi) + 1) / public_key;
}

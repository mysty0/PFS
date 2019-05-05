#include "AsymmetricCryptor.h"

BigInt gcd(BigInt a, BigInt b){
	BigInt temp;
	while (true){
		//std::cout << "sa: " << a << " b: " << b << " temp: " << temp << std::endl;
		temp = a % b;
		if (temp == 0)
			return b;
		a = b;
		b = temp;
		//std::cout << "a: " << a << " b: " << b << " temp: " << temp << std::endl;
	}
}

void AsymmetricCryptor::generate_keys(BigInt& public_key, BigInt& private_key, BigInt& n){
	BigInt p(PrimeGenerator::generate_prime(10000));
	BigInt q(PrimeGenerator::generate_prime(10000));
	//std::cout << "P: " << p << " q: " << q << std::endl;

	n = p * q;

	//std::cout << "n: " << n << std::endl;

	public_key = 2;
	BigInt phi = (p - 1) * (q - 1);
	while (public_key < phi){
		if (gcd(public_key, phi) == 1)
			break;
		else
			++public_key;
		//std::cout << "public_key: " << public_key << std::endl;
	}
	//public_key = 23;
	//std::cout << "phi: " << phi << std::endl;
	//std::cout << "public key: " << public_key << std::endl;

	//BigInt k(2);
	//private_key = ((k * phi) + 1) / public_key;
	BigInt k = 1;

	while (true){
		k = k + phi;

		if (k % public_key == 0){
			private_key = (k / public_key);
			break;
		}
	}
	//std::cout << "private key: " << private_key << "test " << private_key * public_key % phi << "test1 " << private_key.pow_mod(public_key, phi) << std::endl;
}

BigInt AsymmetricCryptor::crypt_key(const BigInt& key, const BigInt& ukey, const BigInt& n){
	return key.pow_mod(ukey, n);
}

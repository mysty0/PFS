#pragma once
#include <vector>
#include <string>

class BigInt{

	bool negative = false;
	std::vector<char> data;

	void normalize();
public:
	BigInt(long long n);
	BigInt(std::string str);
	BigInt();
	~BigInt();

	BigInt operator*(const BigInt& lsh) const;
	BigInt operator/(const BigInt& lsh) const;
	BigInt operator^(const BigInt& lsh) const;
	BigInt operator+(const BigInt& lsh) const;
	BigInt operator-(const BigInt& lsh) const;

	BigInt & operator*=(const BigInt& lsh);
	BigInt& operator/=(const BigInt& lsh);
	BigInt& operator^=(const BigInt& lsh);
	BigInt& operator+=(const BigInt& lsh);
	BigInt& operator-=(const BigInt& lsh);

	BigInt operator-() const;
	BigInt& operator++();

	bool operator>(const BigInt& lsh) const;
	bool operator<(const BigInt& lsh) const;
	bool operator>=(const BigInt& lsh) const;
	bool operator<=(const BigInt& lsh) const;
	bool operator==(const BigInt& lsh) const;
	bool operator!=(const BigInt& lsh) const;
	

	char& operator[](int i);
	char get(int i) const;

	void add_back(char val);

	long long value() const;
	unsigned int size() const;
	void set_negative(bool negative);
	bool is_negative() const;
	
};


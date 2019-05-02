#include "BigInt.h"



BigInt::BigInt()
{
}


BigInt::BigInt(unsigned long long n){

	while (n != 0) {
		data.push_back(n % 10);
		n /= 10;
	}
}

BigInt::~BigInt()
{
}

void BigInt::normalize() {
	for (int i = size() - 1; i >= 0; --i) {
		if (data[i] == 0) data.pop_back();
		else break;
	}
	if ((data.size() == 1 && data[0] == 0) || data.empty()) negative = false;
}

BigInt BigInt::operator*(const BigInt& in) const {
	BigInt res;

	bool bigger = in.size() > size();
	const BigInt& a = bigger ? in : *this;
	const BigInt& b = bigger ? *this : in;

	
	for (int i = 0; i < b.size(); ++i) {
		int rem = 0;
		for (int j = 0; j < a.size(); ++j) {
			int r = a.get(j) * b.get(i) + res[i + j]+rem;
			res[i + j] = r%10;
			rem = r / 10;
		}
		if (rem) res.add_back(rem);
		//int r = data[i] * in[i] + rem;
		//res[i] = r % 10;
		//rem = r / 10;
	}
	return res;
}

BigInt BigInt::operator/(const BigInt& div) const{

	BigInt dividend(*this);
	BigInt quotient(0);
	while (dividend >= div){
		dividend -= div;
		++quotient;
	}
	return quotient;
}

BigInt BigInt::operator^(const BigInt& in) const{
	if (in == BigInt(0)) return BigInt(1);
	if (in == BigInt(1)) return BigInt(*this);
	BigInt res(*this);
	int pw = in.value();
	for (int i = 1; i < pw; ++i) {
		res *= (*this);
	}

	return res;
}

BigInt BigInt::operator+(const BigInt& in) const {
	BigInt res;
	
	bool bigger = in.size() > size();

	BigInt a = bigger ? in : (*this);
	BigInt b = bigger ? (*this) : in;
	
	bool greater = false;
	if (a.is_negative() != b.is_negative()) {
		a.set_negative(false);
		b.set_negative(false);
		greater = a > b;
		if (greater)
			b.set_negative(true);
		else
			a.set_negative(true);
	}

	int rem = 0;
	
	int len = b.size();
	for (int i = 0; i < len; ++i) {
		int r = a.get(i) + b.get(i) + rem;
		if (r < 0) {
			res.add_back(10 + (r % 10));
			rem = -1;
		}
		else {
			res.add_back(r % 10);
			rem = r / 10;
		}
	}
	
	if(a.size() > b.size())
		for (int i = b.size(); i < a.size(); ++i) {
			int r = a.get(i, true) + rem % 10;
			if (r < 0) {
				res.add_back(10 + (r % 10));
				rem = -1;
			}
			else {
				res.add_back(r % 10);
				rem = r / 10;
			}
		}
	
	if (rem) res.add_back(rem);

	if (a.is_negative() != b.is_negative())
		if((greater && bigger && in.is_negative()) || (!greater && bigger && (*this).is_negative()) ||
			(!greater && !bigger && in.is_negative()) || (greater && !bigger && (*this).is_negative()))res.set_negative(true);
		//if ((!a.is_negative() && greater) || (!b.is_negative() && !greater)) res.set_negative(true);

	res.normalize();
	return res;
}

BigInt BigInt::operator-(const BigInt& in) const {
	return (*this) + (-in);
}

BigInt BigInt::operator%(const BigInt& div) const{
	if ((*this) < div) return BigInt(*this);
	BigInt dividend(*this);
	BigInt quotient(0);
	while (dividend >= div) {
		dividend -= div;
		quotient += 1;
	}
	return dividend;
}

BigInt& BigInt::operator*=(const BigInt& in){
	*this = (*this) * in;
	return *this;
}
BigInt& BigInt::operator/=(const BigInt& in){
	*this = (*this) / in;
	return *this;
}

BigInt& BigInt::operator+=(const BigInt& in) {
	*this = (*this) + in;
	return *this;
}

BigInt& BigInt::operator^=(const BigInt& in) {
	*this = (*this) ^ in;
	return *this;
}

BigInt& BigInt::operator-=(const BigInt& lsh){
	*this = (*this) - lsh;
	return *this;
}

BigInt BigInt::operator-() const {
	BigInt res(*this);
	res.set_negative(true);
	return res;
}

BigInt& BigInt::operator++(){
	if (size() == 0) data.push_back(1);
	else {
		int r = data[0] + 1;
		if (r >= 10) {
			data[0] = r;
			for (int i = 0; i < size(); ++i) {
				if (data[i] != 10) break;
				else {
					data[i] = 0;
					if (i == size() - 1) data.push_back(1);
					else data[i + 1] += 1;
				}
			}
		}
		else data[0] = r;
	}
	return *this;
}

bool BigInt::operator>(const BigInt& in) const {
	if (in.is_negative() != is_negative()) return in.is_negative();
	if (in.size() != size()) return size() > in.size();
	else {
		for (int i = size()-1; i >= 0; --i) {
			if (data[i] != in.get(i)) return get(i) > in.get(i);
		}
		return false;
	}
}

bool BigInt::operator<(const BigInt& in) const{
	return !(*this >= in);
}

bool BigInt::operator>=(const BigInt& in) const{
	if (in.is_negative() != is_negative()) return in.is_negative();
	if (in.size() != size()) return size() > in.size();
	else {
		for (int i = size() - 1; i >= 0; --i) {
			if (data[i] != in.get(i)) return get(i) > in.get(i);
		}
		return true;
	}
}

bool BigInt::operator<=(const BigInt& in) const{
	return !(*this > in);
}

bool BigInt::operator==(const BigInt& in) const{
	if (in.is_negative() != is_negative()) return false;
	if (in.size() != size()) return false;
	else {
		for (int i = size() - 1; i >= 0; --i) {
			if (data[i] != in.get(i)) return false;
		}
		return true;
	}
}

bool BigInt::operator!=(const BigInt& lsh) const{
	return !((*this) == lsh);
}

bool BigInt::is_even() const{
	if (data.size() == 0) return true;
	return (data.back() & 1) == 0;
}

char& BigInt::operator[](int i){
	if (i >= data.size()) {
		data.resize(i + 1);
		data[i] = 0;
	}
	return data[i];
}

char BigInt::get(int i, bool abs) const{
	if (abs) return data[i];
	return (negative ? -1 : 1)*data[i];
}

void BigInt::add_back(char val){
	data.push_back(val);
}

long long BigInt::value() const {
	long long res = 0;
	int i = 0;
	for (const char el : data) res += pow(10, i++) * el;
	if (negative) res = -res;
	return res;
}

unsigned int BigInt::size() const {
	return data.size();
}

void BigInt::set_negative(bool negative){
	this->negative = negative;
}

bool BigInt::is_negative() const{
	return negative;
}

std::ostream& operator<<(std::ostream& out, const BigInt val){
	if (val.is_negative()) out << "-";
	for (int i = val.data.size() - 1; i >= 0; --i) out << (int)val.data[i];
	return out;
}

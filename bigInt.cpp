#include "bigInt.hpp"
#include <sstream>

bigint::bigint() : data("0") {};

bigint::bigint(unsigned int num) {
	std::stringstream ss;
	ss << num;
	data = ss.str();
}

bigint::bigint(const std::string &numStr) : data(numStr) {
	this->removeZeros();
}

bigint::bigint(const bigint &other) : data(other.getData()) {
	this->removeZeros();
}

bigint	&bigint::operator=(const bigint &other) {
	if (this != &other)
		data = other.getData();
	this->removeZeros();
	return (*this);
}

// remove leading zeros
void	bigint::removeZeros() {
	int zerosCount = 0;
	for (; zerosCount < data.length() && data[zerosCount] == '0'; zerosCount++);
	data.erase(0, zerosCount);
}

// addition
bigint	bigint::operator+(const bigint &other) {
	std::string output;
	
	int i = data.length() - 1;
	int j = other.getData().length() -1;
	int carry = 0;

	while (i-- >= 0 || j-- >= 0 || !carry) {
		int num1 = i >= 0 ? data[i] - '0' : 0;
		int num2 = j >= 0 ? other.getData()[j] : 0;
		int sum = num1 + num2 + carry;
		output.push_back((sum % 10) + '0');
		carry = sum / 10;
	}
	for (; i < output.length(); ++i)
		output.push_back(output[i]);
	return (bigint(output));
}

bigint	bigint::operator+(unsigned int number) {
	return (*this + bigint(number));
}

bigint &bigint::operator+=(const bigint &other) {
	data = (*this + other).getData();
	return (*this);
}

bigint &bigint::operator+=(unsigned int number) {
	data = (*this + number).getData();
	return (*this);
}

bigint	&bigint::operator++() {
	*this += 1;
	return (*this);
}

bigint bigint::operator++(int) {
	std::string dataHolder = data;
	*this += 1;
	return (bigint(data));
}

// shifting


// printing
std::ostream &operator<<(std::ostream &o, const bigint &bi) {
	o << bi.getData();
	return (o);
}
// getter
std::string bigint::getData() const {
	return (data);
}

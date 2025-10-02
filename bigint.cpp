#include "bigint.hpp"
#include <sstream>


static std::string nbrToStr(int num) {
	std::stringstream ss;
	ss << num;
	return (ss.str());
}

static std::string	addStrings(const std::string &str1, const std::string &str2) {
	std::string outputHolder;
	std::string output;
	int i = str1.length() - 1;
	int	j = str2.length() - 1;
	int carry = 0;
	int holder = 0;

	while (i >= 0 || j >= 0 || carry) {
		holder = carry;
		if (i >= 0)
			holder += str1[i--] - '0';
		if (j >= 0)
			holder += str2[j--] - '0';
		carry = holder / 10;
		outputHolder += (holder % 10) + '0';
	}
	for (i = outputHolder.length() - 1; i >= 0; i--)
		output += outputHolder[i];
	return (output);
}

static int strValComp(const std::string &str1, const std::string &str2) {
	if (str1.length() > str2.length())
		return (1);
	if (str1.length() < str2.length())
		return (2);
	if (str1 == str2)
		return (0);
	for(int i = 0; i < str1.length(); i++) {
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (2);
	}
	return (0);
}

bigint::bigint() : bigNumStr(std::string(1, '0')) {}

bigint::bigint(int num) : bigNumStr(nbrToStr(num)) {}

bigint::bigint(const std::string &strNum) : bigNumStr(strNum) {}

bigint::bigint(const bigint &other) {
	*this = other;
}

bigint	&bigint::operator=(const bigint &other) {
	if (this != &other)
		bigNumStr = other.bigNumStr;
	return (*this);
}

bigint::~bigint() {}

// addition

bigint	bigint::operator+(const bigint &other) const {
	return (addStrings(bigNumStr, other.bigNumStr));
}

bigint	bigint::operator+(int num) const {
	return (addStrings(bigNumStr, nbrToStr(num)));
}

bigint	&bigint::operator+=(const bigint &other) {
	bigNumStr = addStrings(bigNumStr, other.bigNumStr);
	return (*this);
}

bigint	&bigint::operator+=(int num) {
	bigNumStr = addStrings(bigNumStr, nbrToStr(num));
	return (*this);
}

bigint	&bigint::operator++() {
	*this += 1;
	return (*this);
}

bigint	bigint::operator++(int) {
	bigint out(bigNumStr);
	++*this;
	return (out);
}

// shifting
bigint	bigint::operator<<(int num) const {
	if (num <= 0)
		return (bigint(*this));
	return (bigint(bigNumStr + std::string(num, '0')));
}

bigint	bigint::operator<<(const bigint &other) const {
	bigint output = *this;
	bigint i = bigint();
	while (i++ < other)
		output << 1;
	return (output);
}

bigint &bigint::operator<<=(int num) {
	*this = *this << num;
	return (*this);
}

bigint	&bigint::operator<<=(const bigint &other) {
	*this = *this << other;
	return (*this);
}

bigint	bigint::operator>>(const bigint &other) const {
	std::string outputStr = bigNumStr;
	bigint	i = bigint();
	while (i++ < other) {
		if (!outputStr.empty())
			outputStr.erase(outputStr.length() - 1, 1);
	}
	if (outputStr.empty())
		return (bigint("0"));
	return (bigint(outputStr));
}

bigint	bigint::operator>>(int nbr) const {
	return (*this >> bigint(nbr));
}

bigint	&bigint::operator>>=(const bigint &other) {
	*this = *this >> other;
	return (*this);
}

bigint	&bigint::operator>>=(int num) {
	*this = *this >> num;
	return (*this);
}

// compare
bool	bigint::operator<(const bigint &other) const {
	int comFlag = strValComp(this->bigNumStr, other.bigNumStr);
	if (comFlag == 2)
		return (true);
	return (false);
}

bool	bigint::operator<=(const bigint &other) const {
	int compFlag = strValComp(this->bigNumStr, other.bigNumStr);
	if (compFlag == 2 || !compFlag)
		return (true);
	return (false);
}

bool	bigint::operator>(const bigint &other) const {
	int	compFlag = strValComp(this->bigNumStr, other.bigNumStr);
	if (compFlag == 1)
		return (true);
	return (false);
}

bool	bigint::operator>=(const bigint &other) const {
	int compFlag = strValComp(this->bigNumStr, other.bigNumStr);
	if (compFlag == 1 || !compFlag )
		return (true);
	return (false);
}

bool	bigint::operator==(const bigint &other) const {
	int compFlag = strValComp(this->bigNumStr, other.bigNumStr);
	if (!compFlag)
		return (true);
	return (false);
}

bool bigint::operator!=(const bigint &other) const {
	if (*this == other)
		return (false);
	return (true);
}

// getter
std::string	bigint::getData() const {
	return (bigNumStr);
}

// printing 
std::ostream &operator<<(std::ostream &o, const bigint &src) {
	o << src.getData();
	return (o);
}

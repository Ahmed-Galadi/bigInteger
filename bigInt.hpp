#pragma once

#include <iostream>
#include <string>

class bigint {
	private:
		std::string data;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint &other);

		// + addition
		bigint	&operator+(const bigint &other);
		bigint	&operator+=(const bigint &other);
		bigint	&operator++();
		bigint	&operator++(int);
		// + comparison
		bool	operator<(const bigint &other) const;
		bool	operator<=(const bigint &other) const;
		bool	operator>(const bigint &other) const;
		bool	operator>=(const bigint &other) const;
		bool	operator==(const bigint &other) const;
		bool	operator!=(const bigint &other) const;
		// + digit shift
		//		- shift with object
		bigint	&operator<<(const bigint &other);
		bigint  &operator<<=(const bigint &other);
		bigint	&operator>>(const bigint &other);
		bigint	&operator>>=(const bigint &other);
		//		- shift with int
		bigint	&operator<<(int other);
		bigint  &operator<<=(int other);
		bigint	&operator>>(int other);
		bigint	&operator>>=(int other);

		std::string getData() const;
};
// printing
std::ostream &operator<<(std::ostream &o, const bigint &bi);

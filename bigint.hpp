#pragma once

#include <string>
#include <ostream>

class bigint {
	private:
		std::string bigNumStr;
	public:
		bigint();
		bigint(int num);
		bigint(const std::string &strNum);
		bigint(const bigint &other);
		bigint	&operator=(const bigint &other);
		~bigint();
		
		// addition
		bigint	operator+(const bigint &other) const;
		bigint	operator+(int num) const;

		bigint	&operator+=(const bigint &other);
		bigint	&operator+=(int num);
		
		bigint	&operator++();
		bigint	operator++(int);

		// shifting
		bigint	operator<<(const bigint &other) const;
		bigint	operator<<(int num) const;

		bigint	&operator<<=(const bigint &other);
		bigint	&operator<<=(int num);

		bigint	operator>>(const bigint &other) const;
		bigint	operator>>(int num) const;

		bigint	&operator>>=(const bigint &other);
		bigint	&operator>>=(int num);

		// compare
		bool	operator<(const bigint &other) const;
		bool	operator<=(const bigint &other) const;

		bool	operator>(const bigint &other) const;
		bool	operator>=(const bigint &other) const;

		bool	operator==(const bigint &other) const;
		bool	operator!=(const bigint &other) const;

		std::string	getData() const;

};

std::ostream &operator<<(std::ostream &o, const bigint &src);

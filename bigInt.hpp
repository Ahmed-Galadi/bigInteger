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
};

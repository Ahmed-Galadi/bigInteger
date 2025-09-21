#include "bigInt.hpp"
#include <sstream>

bigint::bigint() : data("0") {};

bigint::bigint(unsigned int num) {
	std::stringstream ss;
	ss << num;
	data = ss.str();
}

bigint::bigint(const bigint &other) {
	if (this != &other)
		data = other.getData();
}



// printing
std::ostream &operator<<(std::ostream &o, const bigint &bi) {
	o << bi.getData();
	return (o);
}
// getter
std::string bigint::getData() const {
	return (data);
}

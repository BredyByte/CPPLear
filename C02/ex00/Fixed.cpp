#include "Fixed.hpp"

Fixed::Fixed(const Fixed& copy): _value(copy.getRawBits()) {

}

Fixed& Fixed::operator=(const Fixed& other) {
	
}

Fixed::Fixed() : _value(0) {
}

Fixed::~Fixed() {

}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

int Fixed::getRawBits() const {
	return (_value);
}

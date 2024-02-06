#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

/*---- Constructors ----*/
Fixed::Fixed() : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
	int scalignFactor = 1 << _weight;  //the same pow(2, _weight);;
	_raw = number * scalignFactor;
}

//_raw = roundf(number * (1 << _weight));
Fixed::Fixed(const float number) {
	float scalignFactor = 1.0f;

	for (int i = 0; i < Fixed::_weight; i++) {
		scalignFactor *= 2.0f;
	}
	this->_raw = number * scalignFactor;
}

Fixed::Fixed(const Fixed& copy): _raw(copy.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

/*---- Destructor ----*/
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*---- Operatorst OverLoad ----*/
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_raw = other.getRawBits();

	return *this;
}

/*---- Member Functions ----*/
void Fixed::setRawBits(int const raw) {
	_raw = raw;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_raw) / (1 << _weight);
}

int Fixed::toInt() const {
	return static_cast<int>(_raw) / (1 << _weight);
}


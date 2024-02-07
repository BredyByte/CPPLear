#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

/*-------------- Constructors --------------*/
Fixed::Fixed() : _raw(0) {

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

}

/*-------------- Destructor --------------*/
Fixed::~Fixed() {

}

/*-------------- Operatorst OverLoad --------------*/
// Assigment
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_raw = other.getRawBits();

	return *this;
}

// Comparison
bool Fixed::operator>(const Fixed& other) {
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed& other) {
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) {
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) {
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) {
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) {
	return this->toFloat() != other.toFloat();
}

// Math
Fixed Fixed::operator-(const Fixed& other) {
	Fixed tmp;
	tmp.setRawBits(this->_raw - other.getRawBits());
	return tmp;
}

Fixed Fixed::operator+(const Fixed& other) {
	Fixed tmp;
	tmp.setRawBits(this->_raw + other.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed& other) {
	Fixed tmp;
	tmp.setRawBits((this->_raw * other.getRawBits()) / (1 << _weight));
	return tmp;
}

Fixed Fixed::operator/(const Fixed& other) {
	Fixed tmp;
	tmp.setRawBits(this->toFloat() / other.toFloat() * (1 << _weight));
	return tmp;
}

Fixed& Fixed::operator++() {
	++_raw;
	return *this;
}

Fixed& Fixed::operator--() {
	--_raw;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

/*-------------- Member Functions --------------*/
void Fixed::setRawBits(int const raw) {
	_raw = raw;
}

int Fixed::getRawBits() const {
	return _raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_raw) / (1 << _weight);
}

int Fixed::toInt() const {
	return static_cast<int>(_raw) / (1 << _weight);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
	return (first.getRawBits() < second.getRawBits()) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
	return (first.getRawBits() < second.getRawBits()) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
	return (first.getRawBits() > second.getRawBits()) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
	return (first.getRawBits() > second.getRawBits()) ? first : second;
}

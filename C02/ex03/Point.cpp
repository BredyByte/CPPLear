#include "Point.hpp"

/*-------------- Constructors --------------*/
Point::Point() : _x(0), _y(0) {} // Default
Point::Point(const float x, const float y) : _x(x), _y(y) {} // Float
Point::Point(const Point& other) : _x(other._x), _y(other._y) {} // Copy

/*-------------- Destructor --------------*/
Point::~Point() {}

/*-------------- Operators Overloading --------------*/
Point& Point::operator=(const Point& other) {
	if (this != &other) {
		const_cast<Fixed&>(this->_x) = other._x;
		const_cast<Fixed&>(this->_y) = other._y;
	}

	return *this;
}

/*-------------- Member Functions --------------*/
Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

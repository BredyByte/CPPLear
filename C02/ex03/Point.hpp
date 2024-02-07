#ifndef POINT_HPP
#define  POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
public:
	// Constructor
	Point();								// Def
	Point(const float x, const float y);	  // Float
	Point(const Point& other); 				// Copy

	// Destructor
	~Point();

	// Operators
	Point& operator=(const Point& other);	// Assigment
	Fixed getX() const;
	Fixed getY() const;
	// Member Functions

private:

	Fixed const _x;
	Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif

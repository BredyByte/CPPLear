#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>


class Fixed {
public:
	// Constructor
	Fixed();					// Default
	Fixed(const Fixed& copy);	// Copy
	Fixed(const int number);	// int to fixed-point
	Fixed(const float number);	 // float to fixed-point

	// Destructor
	~Fixed();

	// Operators
	Fixed& operator=(const Fixed& other);

	// Member functions
	int  getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int	 toInt() const;

private:

	int					_raw;
	static const int	_weight = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif

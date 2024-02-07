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
	Fixed& operator=(const Fixed& other);	// Assigment
	bool operator>(const Fixed& other);		// Comparison
	bool operator<(const Fixed& other);		// Comparison
	bool operator<=(const Fixed& other);	// Comparison
	bool operator>=(const Fixed& other);	// Comparison
	bool operator==(const Fixed& other);	// Comparison
	bool operator!=(const Fixed& other);	// Comparison
	Fixed operator-(const Fixed& other);	// Math
	Fixed operator+(const Fixed& other);	// Math
	Fixed operator/(const Fixed& other);	// Math
	Fixed operator*(const Fixed& other);	// Math
	Fixed& operator++();					// Inc-Dec
	Fixed& operator--();					// Inc-Dec
	Fixed  operator++(int);					// Inc-Dec
	Fixed  operator--(int);				// Inc-Dec

	// Member functions
	int  getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int	 toInt() const;
	static Fixed& min(Fixed& first, Fixed& second);
	const static Fixed& min(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	const static Fixed& max(const Fixed& first, const Fixed& second);
private:

	int					_raw;
	static const int	_weight = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
public:
	// Constructor
	Fixed();
	Fixed(const Fixed& copy);

	// Destructor
	~Fixed();

	// Operators
	Fixed& operator=(const Fixed& other);

	// Member functions
	int  getRawBits() const;
	void setRawBits(int const raw);

private:

	int					_value;
	static const int	_weight = 8;
};

#endif

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <sstream>

enum Level {
	DEBUT,
	INFO,
	WARNING,
	ERROR
};

class Harl {
public:
	// Constructor
	Harl();
	// Destructor
	~Harl();
	// Member Functions
	void complain(std::string level);

private:
	void _debut();
	void _info();
	void _warning();
	void _error();
};

#endif

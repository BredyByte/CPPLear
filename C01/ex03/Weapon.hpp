#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
	// Constructor
	Weapon();
	Weapon( std::string type );

	// Destructor
	~Weapon();

	// Other member functions
	const std::string&	getType();
	void				setType(std::string type);

private:
	std::string _type;
};

#endif

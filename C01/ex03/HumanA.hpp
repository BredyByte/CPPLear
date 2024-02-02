#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"


class HumanA {
public:
	// Constructor
	HumanA(std::string name, Weapon& weapon);

	// Destructor
	~HumanA();

	// Member functions
	void attack();

private:
	Weapon&		_weapon;
	std::string _name;

};

#endif

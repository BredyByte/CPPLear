#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	// Constructor
	HumanB(std::string name);

	// Desctructor
	~HumanB();

	// Member functions
	void attack();
	void setWeapon(Weapon& newWeapon);

private:
	Weapon*		_weapon;
	std::string	_name;
};

#endif

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_weapon = nullptr;
	_name = name;
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon& newWeapon) {
	_weapon = &newWeapon;
}


void HumanB::attack() {
	if (_weapon != nullptr) {
		std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
	}
	else {
		std::cout << _name << " has no weapon." << std::endl;
	}
}

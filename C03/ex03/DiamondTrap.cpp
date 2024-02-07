#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	FragTrap::_health = 100;
	FragTrap::_energy = 50;
	FragTrap::_damage = 30;
	std::cout << "DiamondTrap Constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

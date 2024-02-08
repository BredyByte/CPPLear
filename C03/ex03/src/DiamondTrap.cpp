#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("Default") {
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap Constructor " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->_name = name;
	_health = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap Constructor " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::guardGate() {
	std::cout << "DiamondTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void DiamondTrap::printMessage(std::string message, std::string flag, std::string target) {
	if (message.empty() && flag == "ATTACK") {
		std::cout << "DiamondTrap " << this->_name << " attacks " << ((!target.empty()) ? target : "NULL") << ", causing " << this->getDamage() << " points of damage" << std::endl;
	}
	else if (message.empty() && flag == "REPARE") {
		std::cout << "DiamondTrap " << this->_name << " repaired itself, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else if (message.empty() && flag == "TAKEDAMAGE") {
		std::cout << "DiamondTrap " << this->_name << " has taken damage, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else {
		std::cout << "DiamondTrap " << this->_name << (!(message.empty()) ? message : "") << std::endl;
	}
}

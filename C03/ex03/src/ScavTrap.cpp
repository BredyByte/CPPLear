#include "ScavTrap.hpp"

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_damage = other._damage;
	return (*this);
}

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Constructor " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap Constructor " << this->_name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::printMessage(std::string message, std::string flag, std::string target) {
	if (message.empty() && flag == "ATTACK") {
		std::cout << "ScavTrap " << this->_name << " attacks " << ((!target.empty()) ? target : "NULL") << ", causing " << this->_damage << " points of damage" << std::endl;
	}
	else if (message.empty() && flag == "REPARE") {
		std::cout << "ScavTrap " << this->_name << " repaired itself, and now has " << this->_health << " points of health" << std::endl;
	}
	else if (message.empty() && flag == "TAKEDAMAGE") {
		std::cout << "ScavTrap " << this->_name << " has taken damage, and now has " << this->_health << " points of health" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->_name << (!(message.empty()) ? message : "") << std::endl;
	}
}

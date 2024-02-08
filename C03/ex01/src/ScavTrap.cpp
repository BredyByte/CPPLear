#include "ScavTrap.hpp"

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
	if (!checkStamina()) {
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::printMessage(std::string message, std::string flag, std::string target) {
	if (message.empty() && flag == "ATTACK") {
		std::cout << "ScavTrap " << this->getName() << " attacks " << ((!target.empty()) ? target : "NULL") << ", causing " << this->getDamage() << " points of damage" << std::endl;
	}
	else if (message.empty() && flag == "REPARE") {
		std::cout << "ScavTrap " << this->getName() << " repaired itself, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else if (message.empty() && flag == "TAKEDAMAGE") {
		std::cout << "ScavTrap " << this->getName() << " has taken damage, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getName() << (!(message.empty()) ? message : "") << std::endl;
	}
}

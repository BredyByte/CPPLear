#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Constructor " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap Constructor " << this->_name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (!checkStamina()) {
		return ;
	}
	std::cout << "The positive high five request is here" << std::endl;
}

void FragTrap::printMessage(std::string message, std::string flag, std::string target) {
	if (message.empty() && flag == "ATTACK") {
		std::cout << "FragTrap " << this->getName() << " attacks " << ((!target.empty()) ? target : "NULL") << ", causing " << this->getDamage() << " points of damage" << std::endl;
	}
	else if (message.empty() && flag == "REPARE") {
		std::cout << "FragTrap " << this->getName() << " repaired itself, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else if (message.empty() && flag == "TAKEDAMAGE") {
		std::cout << "FragTrap " << this->getName() << " has taken damage, and now has " << this->getHealth() << " points of health" << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->getName() << (!(message.empty()) ? message : "") << std::endl;
	}
}


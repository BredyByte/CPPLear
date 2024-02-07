#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name), _health(obj._health), _energy(obj._energy), _damage(obj._damage) {
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName() {
	return _name;
}

int ClapTrap::getHealth() {
	return _health;
}

int ClapTrap::getEnergy() {
	return _energy;
}

int ClapTrap::getDamage() {
	return _damage;
}

bool ClapTrap::checkStamina() {
	if (this->getHealth() == 0) {
		std::cout << "ClapTrap " << this->getName() << " Is dead :(" << std::endl;
		return false;
	}
	if (this->getEnergy() == 0) {
		std::cout << "ClapTrap " << this->getName() << " Hasn't enough energy :(" << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!checkStamina()) {
		return ;
	}
	if (this->getHealth() == 10) {
		std::cout << "ClapTrap " << this->getName() << " Has max hit point amount." << std::endl;
		return ;
	}
	--(_energy);
	_health = (getHealth() + amount >= 10) ? 10 : getHealth() + amount;
	std::cout << "ClapTrap " << this->getName() << " repaired itself, and now has " << this->getHealth() << " points of health" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!checkStamina()) {
		return ;
	}
	--(_energy);
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage" << std::endl;
}

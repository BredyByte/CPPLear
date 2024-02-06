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

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage" << std::endl;
}

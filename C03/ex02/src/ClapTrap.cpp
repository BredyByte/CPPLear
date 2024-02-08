#include "ClapTrap.hpp"

/*-------------- Operators --------------*/

ClapTrap& ClapTrap::operator=(ClapTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_health = other.getHealth();
		_energy = other.getEnergy();
		_damage = other.getDamage();
	}

	return *this;
}

/*-------------- Constructors --------------*/

ClapTrap::ClapTrap() : _name("NameLess"), _health(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap Constructor " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap Constructor " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int health, int energy, int damage) : _name(name), _health(health), _energy(energy), _damage(damage) {
	std::cout << "ClapTrap Constructor" << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name), _health(obj._health), _energy(obj._energy), _damage(obj._damage) {
	std::cout << "ClapTrap Copy Constructor" << this->_name << std::endl;
}

/*-------------- Destructor --------------*/

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor" << std::endl;
}


/*-------------- Member Functions --------------*/

std::string ClapTrap::getName() {
	return this->_name;
}

int ClapTrap::getHealth() {
	return this->_health;
}

int ClapTrap::getEnergy() {
	return this->_energy;
}

int ClapTrap::getDamage() {
	return this->_damage;
}

void ClapTrap::printMessage(std::string message, std::string flag, std::string target) {
	if (message.empty() && flag == "ATTACK") {
		std::cout << "ClapTrap " << this->_name << " attacks " << ((!target.empty()) ? target : "NULL") << ", causing " << this->_damage << " points of damage" << std::endl;
	}
	else if (message.empty() && flag == "REPARE") {
		std::cout << "ClapTrap " << this->_name << " repaired itself, and now has " << this->_health << " points of health" << std::endl;
	}
	else if (message.empty() && flag == "TAKEDAMAGE") {
		std::cout << "ClapTrap " << this->_name << " has taken damage, and now has " << this->_health << " points of health" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << (!(message.empty()) ? message : "") << std::endl;
	}
}

bool ClapTrap::checkStamina() {
	if (this->getHealth() <= 0) {
		printMessage(" is dead :(", "", "");
		return false;
	}
	if (this->getEnergy() == 0) {
		printMessage(" Hasn't enough energy :(", "", "");
		return false;
	}
	return true;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!checkStamina()) {
		return ;
	}
	--(_energy);
	_health -= amount;
	if (getHealth() <= 0) {
		printMessage(" has died.", "", "");
	}
	else {
		printMessage("", "TAKEDAMAGE", "");
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!checkStamina()) {
		return ;
	}
	--(_energy);
	_health += amount;
	printMessage("", "REPARE", "");
}

void ClapTrap::attack(const std::string& target) {
	if (!checkStamina()) {
		return ;
	}
	--(_energy);
	printMessage("", "ATTACK", target);
}

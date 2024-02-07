#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap Constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "The positive high five request is here" << std::endl;
}

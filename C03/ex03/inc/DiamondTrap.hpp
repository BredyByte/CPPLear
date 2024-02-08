#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
	// Constructor
	DiamondTrap();
	DiamondTrap(std::string name);

	// Destructor
	~DiamondTrap();

	// Member Functions
	void whoAmI();
	void printMessage(std::string message, std::string flag, std::string target);
	void guardGate();
	private:

	std::string _name;
};

#endif

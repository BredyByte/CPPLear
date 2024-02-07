#ifndef DIAMONDTRAP_HPP
#define DIANONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap, public ClapTrap {
	public:
	// Constructor
	DiamondTrap(std::string name);

	// Destructor
	~DiamondTrap();
	// Member Functions
	void whoAmI();

	private:

	std::string _name;
};

#endif

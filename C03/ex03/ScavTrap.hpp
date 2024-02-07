#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap  {
public:
	// Constructor
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap();

	// Member functions
	void guardGate();

private:

};

#endif

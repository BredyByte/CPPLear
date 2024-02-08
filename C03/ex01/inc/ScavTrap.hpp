#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap  {
public:
	// Constructor
	ScavTrap();
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap();
	void printMessage(std::string message, std::string flag, std::string target);

	// Member functions
	void guardGate();

private:

};

#endif
